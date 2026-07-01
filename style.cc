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
   INTERFAZ PARA CELULARES
   ======================================================= */
@media (max-width: 768px) {
    
    /* 1. Hace que todo el cuerpo fluya hacia abajo verticalmente */
    body {
        display: flex !important;
        flex-direction: column !important;
        height: auto !important;
        min-height: 100vh;
        margin: 0 !important;
        padding: 0 !important;
        background-color: #f8f9fa !important; /* Fondo gris claro limpio como iLovePDF */
    }

    /* 2. MENU LATERAL (Elegant PDF): En cel se convierte en una barra superior discreta */
    aside, .sidebar, [class*="sidebar"] {
        width: 100% !important;
        max-width: 100% !important;
        height: auto !important;
        position: relative !important;
        padding: 15px !important;
        box-sizing: border-box;
        display: flex !important;
        flex-direction: column !important;
        align-items: center !important;
        text-align: center;
        border-bottom: 2px solid rgba(0,0,0,0.1);
    }

    /* Oculta los otros enlaces del menú que estorban en cel para que no se amontonen */
    aside a, .sidebar a, .sidebar nav, [class*="sidebar"] ul {
        display: none !important; /* iLovePDF solo muestra la herramienta actual en uso */
    }

    /* Mantiene solo el título "Elegant PDF" visible arriba */
    aside h1, .sidebar h1, [class*="sidebar"] .logo {
        display: block !important;
        margin: 0 !important;
        font-size: 22px !important;
    }

    /* 3. ZONA BLANCA PRINCIPAL: Se expande al 100% ocupando toda la pantalla */
    main, .main-content, [class*="content"], [class*="container"] {
        flex: 1 !important;
        width: 100% !important;
        max-width: 100% !important;
        padding: 20px !important;
        margin: 0 !important;
        box-sizing: border-box;
        display: flex !important;
        flex-direction: column !important;
        justify-content: space-between !important; /* Empuja los botones abajo */
    }

    /* 4. EL CUADRO DE ARRASTRAR PDF: Se vuelve gigante y cómodo para el dedo */
    .drop-zone, [class*="dropzone"], [class*="upload"] {
        width: 100% !important;
        height: 280px !important; /* Altura ideal fija para celulares */
        margin: 20px 0 !important;
        display: flex !important;
        flex-direction: column !important;
        justify-content: center !important;
        align-items: center !important;
    }

    /* 5. BOTONES DE ACCIÓN: Se alinean abajo, grandes y de lado a lado */
    .buttons-container, [class*="buttons"], .action-buttons {
        display: flex !important;
        flex-direction: column !important; /* Uno abajo del otro */
        gap: 12px !important;
        width: 100% !important;
        margin-top: auto !important; /* Se pegan al final de la pantalla */
        padding-bottom: 20px !important;
    }

    /* Botones gigantes estilo app móvil */
    button, .btn, [class*="button"] {
        width: 100% !important;
        height: 50px !important; /* Más altos para que sea fácil picarles con el pulgar */
        font-size: 16px !important;
        font-weight: bold !important;
        margin: 0 !important;
        border-radius: 8px !important;
    }
}