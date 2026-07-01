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
          flex-direction: column;
          padding: 10px;
      }
}