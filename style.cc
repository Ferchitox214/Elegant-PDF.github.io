.resolucion {
    width: 99%;
    text-align: center;
}

/**Movil**/
@media (min-width: 767px) {
    .desktop {
        display: block;
    }
    .Tablet {
        display: none;
    }
}

/**Tablet**/
@media (min-width: 768px) and (max-width: 990px) {
    .desktop {
        display: none;
    }
    .Movil {
        display: block;
    }
}

/**Escritorio**/
@media (min-width: 992px) {
    .desktop {
        display: block;
    }
    .Movil {
        display: none;
    }
}

    }
}

:root {
    --primary: #0b0f19;        /* Fondo oscuro profundo moderno */
    --sidebar-bg: #111827;     /* Fondo de la barra lateral */
    --accent: #f97316;         /* Naranja Eléctrico Vibrante */
    --accent-glow: rgba(249, 115, 22, 0.25);
    --bg: #090d16;             /* Fondo general de la app */
    --card-bg: #ffffff;        /* Blanco para el contenedor principal de herramientas */
    --text-dark: #0f172a;      /* Texto principal oscuro dentro de la tarjeta blanca */
    --text-muted: #64748b;     /* Texto secundario gris */
    --text-light: #f8fafc;     /* Texto blanco para la barra lateral */
    --danger: #ef4444;         /* Rojo moderno para alertas/cancelar */
}

* { 
    margin: 0; 
    padding: 0; 
    box-sizing: border-box; 
}

body {
    font-family: 'Inter', sans-serif;
    background-color: var(--bg);
    color: var(--text-light);
    display: flex;
    min-height: 100vh;
    overflow-x: hidden;
}

/* ==========================================================================
   HEADER PARA CELULARES (Solo se activa en pantallas chicas)
   ========================================================================== */
.mobile-header {
    display: none;
    width: 100%;
    background: var(--sidebar-bg);
    padding: 15px 20px;
    align-items: center;
    justify-content: space-between;
    position: fixed;
    top: 0; 
    left: 0;
    z-index: 100;
    box-shadow: 0 4px 20px rgba(0,0,0,0.3);
    border-bottom: 1px solid rgba(255,255,255,0.05);
}

.mobile-header h1 {
    font-family: 'Orbitron', sans-serif;
    font-size: 20px;
    color: var(--accent);
    letter-spacing: 1px;
}

.menu-toggle {
    background: transparent;
    border: none;
    color: var(--text-light);
    font-size: 24px;
    cursor: pointer;
    transition: color 0.3s;
}

.menu-toggle:hover {
    color: var(--accent);
}

/* ==========================================================================
   BARRA LATERAL (Escritorio / Laptop)
   ========================================================================== */
nav {
    width: 300px;
    background-color: var(--sidebar-bg);
    color: var(--text-light);
    padding: 40px 20px;
    display: flex;
    flex-direction: column;
    box-shadow: 5px 0 25px rgba(0,0,0,0.3);
    height: 100vh;
    position: fixed;
    top: 0; 
    left: 0;
    z-index: 99;
    overflow-y: auto;
    transition: transform 0.4s cubic-bezier(0.4, 0, 0.2, 1);
    border-right: 1px solid rgba(255,255,255,0.05);
}

nav::-webkit-scrollbar { 
    width: 5px; 
}
nav::-webkit-scrollbar-thumb { 
    background: rgba(255, 255, 255, 0.1); 
    border-radius: 10px; 
}

nav h1 {
    font-family: 'Orbitron', sans-serif;
    font-size: 24px;
    margin-bottom: 35px;
    color: var(--accent);
    text-align: center;
    letter-spacing: 1px;
}

.nav-section-title {
    font-size: 11px;
    text-transform: uppercase;
    letter-spacing: 1.5px;
    color: var(--accent);
    margin: 25px 0 10px 10px;
    font-weight: 700;
    opacity: 0.9;
}

.tool-btn {
    background: transparent;
    border: none;
    color: #94a3b8;
    padding: 12px 15px;
    text-align: left;
    font-size: 14px;
    cursor: pointer;
    border-radius: 10px;
    transition: all 0.25s ease;
    margin-bottom: 4px;
    display: flex;
    align-items: center;
    gap: 12px;
    width: 100%;
}

.tool-btn:hover {
    background: rgba(255, 255, 255, 0.03);
    color: var(--text-light);
    padding-left: 20px;
}

.tool-btn.active {
    border-left: 4px solid var(--accent);
    background: rgba(249, 115, 22, 0.1);
    color: var(--text-light);
    font-weight: 600;
}

/* ==========================================================================
   ÁREA DE TRABAJO PRINCIPAL (Contenedor Blanco Premium)
   ========================================================================== */
main {
    flex-grow: 1;
    margin-left: 300px;
    padding: 40px;
    display: flex;
    align-items: center;
    justify-content: center;
    min-height: 100vh;
    width: calc(100% - 300px);
    transition: all 0.4s;
}

.container {
    max-width: 750px;
    width: 100%;
    background: var(--card-bg); /* Fondo Blanco Limpio */
    padding: 50px 40px;
    border-radius: 24px;
    box-shadow: 0 20px 40px rgba(0, 0, 0, 0.25);
    text-align: center;
    color: var(--text-dark);
}

.header-area h2 {
    font-family: 'Orbitron', sans-serif;
    font-size: 32px;
    margin-bottom: 12px;
    color: var(--text-dark);
}

.header-area p {
    color: var(--text-muted);
    margin-bottom: 40px;
    font-size: 15px;
}

/* ZONA DE ARRASTRE DE ARCHIVOS */
.drop-zone {
    border: 2px dashed rgba(249, 115, 22, 0.4);
    border-radius: 16px;
    padding: 60px 20px;
    background: #f8fafc;
    cursor: pointer;
    transition: 0.3s all ease;
    position: relative;
}

.drop-zone:hover {
    border-color: var(--accent);
    background: rgba(249, 115, 22, 0.02);
    box-shadow: 0 0 15px var(--accent-glow);
}

.drop-zone i {
    font-size: 48px;
    color: var(--accent);
    margin-bottom: 20px;
}

.drop-zone p {
    color: var(--text-dark);
    font-weight: 500;
}

.drop-zone input {
    position: absolute;
    width: 100%; 
    height: 100%;
    top: 0; 
    left: 0;
    opacity: 0;
    cursor: pointer;
}

/* BOTONES DE ACCIÓN */
.action-group {
    margin-top: 40px;
    display: flex;
    gap: 15px;
    justify-content: center;
}

.btn {
    padding: 14px 32px;
    border-radius: 12px;
    font-weight: 600;
    cursor: pointer;
    border: none;
    transition: all 0.25s ease;
    display: flex;
    align-items: center;
    gap: 10px;
    font-size: 14px;
}

.btn-main { 
    background: var(--accent); 
    color: white; 
    box-shadow: 0 4px 12px var(--accent-glow);
}

.btn-main:hover { 
    background: #ea580c; 
    transform: translateY(-2px);
    box-shadow: 0 6px 20px rgba(249, 115, 22, 0.4);
}

.btn-main:disabled { 
    background: #cbd5e1; 
    color: #94a3b8; 
    cursor: not-allowed; 
    box-shadow: none;
    transform: none;
}

.btn-cancel { 
    background: #f1f5f9; 
    color: var(--danger); 
}

.btn-cancel:hover { 
    background: #fee2e2; 
}

/* LISTA DE ARCHIVOS */
#file-list {
    margin-top: 25px;
    text-align: left;
    font-size: 14px;
    max-height: 150px;
    overflow-y: auto;
}

.file-item {
    background: #f1f5f9;
    border: 1px solid #e2e8f0;
    padding: 12px 20px;
    border-radius: 10px;
    margin-bottom: 6px;
    display: flex;
    justify-content: space-between;
    align-items: center;
    color: var(--text-dark);
}

.counter-badge {
    margin-top: 25px;
    font-size: 12px;
    color: var(--text-muted);
    letter-spacing: 0.5px;
}

/* CAPA OSCURA DE FONDO PARA EL MENÚ EN CELULARES */
.sidebar-overlay {
    display: none;
    position: fixed;
    top: 0; 
    left: 0;
    width: 100vw; 
    height: 100vh;
    background: rgba(0, 0, 0, 0.6);
    z-index: 98;
    backdrop-filter: blur(4px);
}

/* ==========================================================================
   INTERFAZ TÁCTIL EXCLUSIVA PARA CELULARES (Estilo iLovePDF)
   ========================================================================== */
@media (max-width: 992px) {
    .mobile-header { 
        display: flex; 
    }
    
    nav {
        transform: translateX(-100%); /* Escondido a la izquierda */
        padding-top: 80px; 
        width: 280px;
    }

    nav.open {
        transform: translateX(0); /* Entra deslizándose con suavidad */
    }

    main {
        margin-left: 0;
        width: 100%;
        padding: 90px 16px 30px 16px; /* Espacio superior para que no tape la barra móvil */
    }

    .sidebar-overlay.active {
        display: block;
    }

    .container {
        padding: 35px 20px;
    }
    
    .action-group {
        flex-direction: column-reverse; /* El botón principal queda arriba en celular, más cómodo */
    }
    
    .btn { 
        width: 100%; 
        justify-content: center; 
    }
}