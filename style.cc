* {
    box-sizing: border-box;
    margin: 0;
    padding: 0;
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
}

body {
    background-color: #f4f7f6;
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh;
}

.card {
    background: #ffffff;
    padding: 40px;
    border-radius: 12px;
    box-shadow: 0 8px 24px rgba(0,0,0,0.05);
    text-align: center;
    max-width: 500px;
    width: 100%;
}

h1 {
    color: #e53935; /* Un color rojo similar al de iLovePDF */
    margin-bottom: 10px;
}

.subtitle {
    color: #666;
    font-size: 14px;
    margin-bottom: 30px;
}

.drop-zone {
    border: 2px dashed #e53935;
    border-radius: 8px;
    padding: 40px 20px;
    background-color: #fff8f8;
    cursor: pointer;
    position: relative;
    margin-bottom: 25px;
    transition: background 0.3s;
}

.drop-zone:hover {
    background-color: #ffebee;
}

/* Ocultamos el input feo por defecto pero lo dejamos cliqueable en toda la zona */
.drop-zone input[type="file"] {
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    opacity: 0;
    cursor: pointer;
}

#file-count {
    display: block;
    margin-top: 15px;
    font-size: 13px;
    color: #888;
    font-weight: bold;
}

button {
    background-color: #e53935;
    color: white;
    border: none;
    padding: 12px 30px;
    font-size: 16px;
    font-weight: bold;
    border-radius: 6px;
    cursor: pointer;
    width: 100%;
    transition: background 0.3s;
}

button:hover {
    background-color: #d32f2f;
}

button:disabled {
      background-color: #cccccc;
      cursor: not-allowed;
}

/* =======================================================
    INTERFAZ EXCLUSIVA PARA CELULARES (ESTILO ILOVEPDF)
   ======================================================= */
@media (max-width: 768px) {
    
    /* 1. Fondo gris claro y scroll vertical natural */
    body {
        display: block !important;
        height: auto !important;
        min-height: 100vh !important;
        background-color: #f4f4f7 !important; 
        padding: 15px !important;
        margin: 0 !important;
    }

    /* 2. MENU LATERAL: En celular pasa a ser solo un encabezado superior */
    aside, .sidebar, [class*="sidebar"] {
        width: 100% !important;
        max-width: 100% !important;
        height: auto !important;
        position: relative !important;
        background: #ffffff !important;
        box-shadow: 0 2px 4px rgba(0,0,0,0.05) !important;
        padding: 15px !important;
        margin-bottom: 20px !important;
        border-radius: 10px !important;
        text-align: center !important;
    }

    /* Oculta la lista de enlaces amontonados del menú en cel */
    aside a, .sidebar a, .sidebar nav, [class*="sidebar"] ul, [class*="sidebar"] li {
        display: none !important; 
    }

    /* Destaca el nombre de tu App arriba en el centro */
    aside h1, .sidebar h1, [class*="sidebar"] .logo {
        display: block !important;
        margin: 0 !important;
        font-size: 20px !important;
        color: #0f172a !important;
        font-weight: bold !important;
    }

    /* 3. ZONA CONTENEDORA DE LAS HERRAMIENTAS */
    main, .main-content, [class*="content"], [class*="container"] {
        width: 100% !important;
        max-width: 100% !important;
        margin: 0 !important;
        padding: 0 !important;
        background: transparent !important; /* Quita fondos pesados */
        box-shadow: none !important;
    }

    /* 4. LA MAGIA: Cuadrícula de 2 columnas como iLovePDF */
    .grid-container, .tools-grid, [class*="grid"], [class*="buttons-layout"] {
        display: grid !important;
        grid-template-columns: repeat(2, 1fr) !important; /* Exactamente 2 botones por fila */
        gap: 12px !important; /* Espacio limpio entre tarjetas */
        padding: 5px !important;
    }

    /* 5. TARJETAS / BOTONES: Se vuelven bloques interactivos con forma de app */
    button, .card, .tool-card, [class*="button"] {
        display: flex !important;
        flex-direction: column !important; /* Ícono arriba, texto abajo */
        align-items: center !important;
        justify-content: center !important;
        background-color: #ffffff !important; /* Fondo blanco limpio para cada botón */
        color: #333333 !important;
        height: 120px !important; /* Altura perfecta tipo tarjeta cuadrada */
        width: 100% !important;
        padding: 15px !important;
        border: 1px solid #e2e8f0 !important;
        border-radius: 12px !important; /* Bordes suavemente redondeados */
        box-shadow: 0 4px 6px rgba(0,0,0,0.02) !important;
        transition: transform 0.2s !important;
        cursor: pointer !important;
        font-size: 14px !important;
        font-weight: 600 !important;
        box-sizing: border-box !important;
    }

    /* Efecto sutil al pulsar con el dedo */
    button:active, .card:active {
        transform: scale(0.96) !important;
        background-color: #f8fafc !important;
    }

    /* Si usas iconos dentro del botón (SVG o imágenes), los acomoda centrados */
    button img, button svg, [class*="icon"] {
        margin-bottom: 8px !important;
        width: 32px !important;
        height: 32px !important;
    }
}