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

/* --- CONFIGURACIÓN PARA CELULARES --- */
@media (max-width: 768px) {
    body {
        flex-direction: column !important; /* Pone el menú arriba y el contenido abajo */
        height: auto !important;
        min-height: 100vh;
        padding: 0 !important;
    }

    /* Ajuste para el menú oscuro de la izquierda (organizadores) */
    aside, .sidebar, [class*="sidebar"], [class*="menu"] {
        width: 100% !important;
        max-width: 100% !important;
        height: auto !important;
        padding: 15px !important;
        box-sizing: border-box;
    }

    /* Ajuste para la zona blanca de la derecha (donde se sube el PDF) */
    main, .main-content, [class*="content"], [class*="container"] {
        width: 100% !important;
        max-width: 100% !important;
        padding: 20px !important;
        box-sizing: border-box;
    }

    /* Ajuste para los botones de abajo (Cancelar, Procesar) */
    .buttons-container, [class*="buttons"] {
        flex-direction: column !important;
        gap: 10px !important;
        width: 100% !important;
    }

    button {
        width: 100% !important; /* Los botones ocupan todo el ancho en cel */
    }
}