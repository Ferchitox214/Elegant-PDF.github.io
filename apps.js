async function processFiles() {
    const files = mainInput.files;
    if (!files || files.length === 0) return;
    
    // Configurar el botón principal en estado de carga animada
    processBtn.disabled = true;
    processBtn.style.background = "var(--accent)";
    processBtn.style.boxShadow = "0 0 20px var(--accent-glow)";
    
    // Creamos una barra de progreso visual fluida dentro del botón
    processBtn.innerHTML = `
        <div style="width: 100%; background: rgba(0,0,0,0.2); border-radius: 6px; height: 8px; overflow: hidden; margin-bottom: 4px;">
            <div id="progress-bar-inner" style="width: 0%; height: 100%; background: #ffffff; transition: width 0.4s ease;"></div>
        </div>
        <span id="progress-text" style="font-size: 12px; font-family: 'Orbitron', sans-serif;">Analizando carga...</span>
    `;

    const progressBarInner = document.getElementById('progress-bar-inner');
    const progressText = document.getElementById('progress-text');

    // 1. CONTROL DE PESO MÁXIMO (Simulación de carga pesada: ej. más de 15MB en total)
    let totalSize = 0;
    for (let f of files) { totalSize += f.size; }
    const maxAllowedSize = 15 * 1024 * 1024; // 15 Megabytes

    // Animación fluida de análisis inicial
    await new Promise(resolve => setTimeout(resolve, 800));
    progressBarInner.style.width = "30%";
    progressText.innerText = "Procesando bytes...";

    if (totalSize > maxAllowedSize) {
        // ERROR: Transición fluida al estado Rojo de falla
        await new Promise(resolve => setTimeout(resolve, 600));
        progressBarInner.style.width = "100%";
        progressBarInner.style.background = "var(--danger)";
        
        // Estilo rojo futurista de error para el botón
        processBtn.style.background = "var(--danger)";
        processBtn.style.boxShadow = "0 0 25px rgba(239, 68, 68, 0.5)";
        processBtn.style.color = "#ffffff";
        progressText.innerHTML = `<i class="fa-solid fa-triangle-exclamation"></i> Error: Carga muy pesada`;

        alert("No es posible hacer el archivo, carga muy pesada");
        
        // Dejar el estado de error visible un momento antes de resetear con fluidez
        await new Promise(resolve => setTimeout(resolve, 3000));
        resetApp();
        return;
    }

    // 2. PROCESAMIENTO EXITOSO (Si pasa el filtro de peso)
    try {
        progressBarInner.style.width = "70%";
        progressText.innerText = "Sintetizando PDF...";
        await new Promise(resolve => setTimeout(resolve, 700));

        if (currentTool === 'merge') {
            await mergePDFs(files);
        } else if (currentTool === 'jpg') {
            await imagesToPDF(files);
        } else {
            await simulateDocumentProcess(files);
        }

        // Efecto animado de finalización exitosa (¡Listo!)
        progressBarInner.style.width = "100%";
        progressBarInner.style.background = "#10b981"; // Verde éxito futurista
        processBtn.style.background = "#10b981";
        processBtn.style.boxShadow = "0 0 25px rgba(16, 185, 129, 0.6)";
        progressText.innerHTML = `<i class="fa-solid fa-check-double"></i> ¡Listo! Descargado`;
        
        // Espera un momento para que el usuario disfrute la animación de éxito
        await new Promise(resolve => setTimeout(resolve, 2000));

    } catch (e) {
        // En caso de cualquier otro fallo inesperado en las librerías
        processBtn.style.background = "var(--danger)";
        progressText.innerHTML = `<i class="fa-solid fa-circle-xmark"></i> Error inesperado`;
        alert("Error al procesar: " + e.message);
        await new Promise(resolve => setTimeout(resolve, 2000));
    } finally {
        resetApp();
    }
}