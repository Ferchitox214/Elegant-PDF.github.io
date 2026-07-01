async function processFiles() {
    const files = mainInput.files;
    if (!files || files.length === 0) return;
    
    processBtn.disabled = true;
    processBtn.style.background = "var(--accent)";
    processBtn.style.boxShadow = "0 0 20px var(--accent-glow)";
    
    processBtn.innerHTML = `
        <div style="width: 100%; background: rgba(0,0,0,0.2); border-radius: 6px; height: 8px; overflow: hidden; margin-bottom: 4px;">
            <div id="progress-bar-inner" style="width: 0%; height: 100%; background: #ffffff; transition: width 0.4s ease;"></div>
        </div>
        <span id="progress-text" style="font-size: 12px; font-family: 'Orbitron', sans-serif;">Analizando estructura...</span>
    `;

    const progressBarInner = document.getElementById('progress-bar-inner');
    const progressText = document.getElementById('progress-text');

    let totalSize = 0;
    for (let f of files) { totalSize += f.size; }
    const maxAllowedSize = 15 * 1024 * 1024;

    await new Promise(resolve => setTimeout(resolve, 600));

    if (totalSize > maxAllowedSize) {
        progressBarInner.style.width = "100%";
        progressBarInner.style.background = "var(--danger)";
        processBtn.style.background = "var(--danger)";
        processBtn.style.boxShadow = "0 0 25px rgba(239, 68, 68, 0.5)";
        progressText.innerHTML = `<i class="fa-solid fa-triangle-exclamation"></i> Error: Carga pesada`;
        alert("No es posible hacer el archivo, carga muy pesada");
        await new Promise(resolve => setTimeout(resolve, 2000));
        resetApp();
        return;
    }

    try {
        progressBarInner.style.width = "40%";
        progressText.innerText = "Extrayendo información...";

        if (currentTool === 'merge') {
            await mergePDFs(files);
        } else if (currentTool === 'jpg') {
            await imagesToPDF(files);
        } else if (currentTool === 'toword') {
            await convertPdfToWord(files[0]); 
        } else {
            await processStandardPdfTool(files);
        }

        progressBarInner.style.width = "100%";
        progressBarInner.style.background = "#10b981";
        processBtn.style.background = "#10b981";
        processBtn.style.boxShadow = "0 0 25px rgba(16, 185, 129, 0.6)";
        progressText.innerHTML = `<i class="fa-solid fa-check-double"></i> ¡Completado!`;
        
        await new Promise(resolve => setTimeout(resolve, 1500));

    } catch (e) {
        progressBarInner.style.width = "100%";
        progressBarInner.style.background = "var(--danger)";
        processBtn.style.background = "var(--danger)";
        progressText.innerHTML = `<i class="fa-solid fa-circle-xmark"></i> Error de conversión`;
        alert("No fue posible procesar este formato de archivo.");
        await new Promise(resolve => setTimeout(resolve, 2000));
    } finally {
        resetApp();
    }
}

async function convertPdfToWord(file) {
    const bytes = await file.arrayBuffer();
    const pdf = await PDFLib.PDFDocument.load(bytes);
    const pages = pdf.getPages();
    
    let textoExtraido = `Documento traducido desde Elegant PDF\nArchivo original: ${file.name}\n\n`;
    
    pages.forEach((page, index) => {
        textoExtraido += `--- Página ${index + 1} ---\n\n`;
    });

    const doc = new docx.Document({
        sections: [{
            properties: {},
            children: [
                new docx.Paragraph({
                    children: [
                        new docx.TextRun({
                            text: textoExtraido,
                            font: "Arial",
                            size: 24,
                        }),
                    ],
                }),
            ],
        }],
    });

    const blob = await docx.Packer.toBlob(doc);
    const url = URL.createObjectURL(blob);
    
    const a = document.createElement('a');
    a.href = url;
    a.download = `${file.name.replace('.pdf', '')}_ElegantPDF.docx`;
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
}

async function processStandardPdfTool(files) {
    const mergedPdf = await PDFLib.PDFDocument.create();
    for (const file of files) {
        const bytes = await file.arrayBuffer();
        const pdf = await PDFLib.PDFDocument.load(bytes);
        const pages = await mergedPdf.copyPages(pdf, pdf.getPageIndices());
        pages.forEach(p => mergedPdf.addPage(p));
    }
    const result = await mergedPdf.save();
    totalPagesGenerated += 1;
    updateCounterDisplay();
    download(result, `ElegantPDF_Resultado.pdf`, "application/pdf");
}

async function mergePDFs(files) {
    const mergedPdf = await PDFLib.PDFDocument.create();
    let pageCount = 0;
    for (const file of files) {
        const bytes = await file.arrayBuffer();
        const pdf = await PDFLib.PDFDocument.load(bytes);
        const pages = await mergedPdf.copyPages(pdf, pdf.getPageIndices());
        pages.forEach(p => {
            mergedPdf.addPage(p);
            pageCount++;
        });
    }
    const result = await mergedPdf.save();
    totalPagesGenerated += pageCount;
    updateCounterDisplay();
    download(result, `ElegantPDF_Merged.pdf`, "application/pdf");
}

async function imagesToPDF(files) {
    const pdfDoc = await PDFLib.PDFDocument.create();
    let pageCount = 0;
    for (const file of files) {
        const bytes = await file.arrayBuffer();
        let img;
        if (file.type === "image/png" || file.name.toLowerCase().endsWith('.png')) {
            img = await pdfDoc.embedPng(bytes);
        } else {
            img = await pdfDoc.embedJpg(bytes);
        }
        const page = pdfDoc.addPage([img.width, img.height]);
        page.drawImage(img, { x: 0, y: 0, width: img.width, height: img.height });
        pageCount++;
    }
    const result = await pdfDoc.save();
    totalPagesGenerated += pageCount;
    updateCounterDisplay();
    download(result, `ElegantPDF_Images.pdf`, "application/pdf");
}

function updateCounterDisplay() {
    pagesCounter.innerText = `Páginas procesadas en la sesión: ${totalPagesGenerated}`;
}

function download(bytes, name, mimeType) {
    const blob = new Blob([bytes], { type: mimeType });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = name;
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
}