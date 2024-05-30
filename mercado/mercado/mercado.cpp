#include <mysql.h>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int q_estado;

/*
void subMenuAdmin(MYSQL* conectar);
void subMenuPuesto(MYSQL* conectar);
void subMenuGestionClientes(MYSQL* conectar);
void subMenuGestionVentas(MYSQL* conectar);
void subMenuEmpleados(MYSQL* conectar);
void subMenuProveedores(MYSQL* conectar);
void subMenuProductos(MYSQL* conectar);

//funciones
void agregarPuesto(MYSQL* conectar);
void mostrarPuestos(MYSQL* conectar);
void agregarCliente(MYSQL* conectar);
void mostrarError(MYSQL* conectar);
void mostrarCliente(MYSQL* conectar);
void registrarVenta(MYSQL* conectar);
void mostrarVentas(MYSQL* conectar);
void agregarEmpleado(MYSQL* conectar);*/

void subMenuAdmin(MYSQL* conectar);
void subMenuPuesto(MYSQL* conectar);
void subMenuGestionClientes(MYSQL* conectar);
void subMenuGestionVentas(MYSQL* conectar);
void subMenuEmpleados(MYSQL* conectar);
void subMenuProveedores(MYSQL* conectar);
void subMenuProductos(MYSQL* conectar);

//funciones
void agregarMarca(MYSQL* conectar);
void agregarProductos(MYSQL* conectar);
void mostrarMarca(MYSQL* conectar);
void editarProducto(MYSQL* conectar);
void mostrarProducto(MYSQL* conectar);
void agregarPuesto(MYSQL* conectar);
void mostrarPuestos(MYSQL* conectar);
void agregarCliente(MYSQL* conectar);
void mostrarError(MYSQL* conectar);
void mostrarCliente(MYSQL* conectar);
void registrarVenta(MYSQL* conectar);
void mostrarVentas(MYSQL* conectar);
void agregarEmpleado(MYSQL* conectar);
void editarPuesto(MYSQL* conectar);
void mostrarEmpleados(MYSQL* conectar);
void editarEmpleado(MYSQL* conectar);
void agregarProveedor(MYSQL* conectar);
void mostrarProveedor(MYSQL* conectar);
void editarProveedor(MYSQL* conectar);
bool validarNIT(const string& nit);
bool buscarClientePorNIT(MYSQL* conectar, const string& nit, string& nombres, string& apellidos);
void agregarClienteSiNoExiste(MYSQL* conectar, const string& nit);


int main() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "Elias174+-", "db_supermercado", 3306, NULL, 0);

    if (conectar) {
        int opcion;
        do {
            cout << "===== SUPERECONOMICO =====" << endl;
            cout << "1. ADMIN" << endl;
            cout << "2. GESTION CLIENTES" << endl;
            cout << "3. GESTION PRODUCTOS" << endl;
            cout << "4. GESTION VENTAS" << endl;
            cout << "5. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            cin.ignore(); // Ignorar el salto de línea pendiente después de cin
            system("cls");


            switch (opcion) {
            case 1:
                subMenuAdmin(conectar);
                system("cls");
                break;
            case 2:
                subMenuGestionClientes(conectar);
                system("cls");
                break;
            case 3:
                // Puedes agregar un submenú aquí si es necesario
                cout << "caso 3 prueba" << endl;
                break;
            case 4:
                subMenuGestionVentas(conectar);
                system("cls");
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
            }
        } while (opcion != 5);
    }
    else {
        cout << "Error en la conexion..." << endl;
    }

    mysql_close(conectar);
    return 0;
}

void subMenuAdmin(MYSQL* conectar) {
    int opcion;
    do {
        cout << "===== SUBMENU ADMIN =====" << endl;
        cout << "1. Puestos" << endl;
        cout << "2. Empleados" << endl;
        cout << "3. Proveedores" << endl;
        cout << "4. Productos" << endl;
        cout << "5. Salir al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin
        system("cls");
        switch (opcion) {
        case 1:
            subMenuPuesto(conectar);
            break;
        case 2:
            subMenuEmpleados(conectar);
            break;
        case 3:
            subMenuProveedores(conectar);
            break;
        case 4:
            subMenuProductos(conectar);
            break;
        case 5:
            // Regresar al menú principal
            system("cls");
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}


void subMenuPuesto(MYSQL* conectar) {
    int opcion;
    do {
        cout << "===== SUBMENU GESTION PUESTOS =====" << endl;
        cout << "1. Agregar Puestos" << endl;
        cout << "2. Editar Puestos" << endl;
        cout << "3. Mostrar Puestos" << endl;
        cout << "4. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin
        system("cls");
        switch (opcion) {
        case 1:
            agregarPuesto(conectar);

            break;
        case 2:
            editarPuesto(conectar);
            break;
        case 3:
            mostrarPuestos(conectar);
            break;

        case 4:
            // Regresar al menú principal
            system("cls");
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
}

void subMenuGestionClientes(MYSQL* conectar) {
    int opcion;
    do {
        cout << "===== SUBMENU GESTION CLIENTES =====" << endl;
        cout << "1. Agregar Cliente" << endl;
        cout << "2. Mostrar Clientes" << endl;
        cout << "3. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin
        system("cls");
        switch (opcion) {
        case 1:
            agregarCliente(conectar);
            
            break;
        case 2:
            mostrarCliente(conectar);
            break;
        case 3:
            // Regresar al menú principal
            system("cls");
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
}

void subMenuEmpleados(MYSQL* conectar) {
    int opcion;
    do {
        cout << "===== SUBMENU GESTION EMPLEADOS =====" << endl;
        cout << "1. Agregar empleado" << endl;
        cout << "2. Editar empleados" << endl;
        cout << "3. Mostrar empleados" << endl;
        cout << "4. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin
        system("cls");
        switch (opcion) {
        case 1:
            agregarEmpleado(conectar);

            break;
        case 2:
            editarEmpleado(conectar);
            break;
        case 3:
            mostrarEmpleados(conectar);
            break;
        case 4:
            // Regresar al menú principal
            system("cls");
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
}
void agregarCliente(MYSQL* conectar) {
    string nombres, apellidos, nit, genero, correo;
    int telefono;

    cout << "===== REGISTRO DE NUEVO CLIENTE =====" << endl << endl;

    cout << "Ingrese los nombres: ";
    getline(cin, nombres);

    cout << "Ingrese los apellidos: ";
    getline(cin, apellidos);

    cout << "Ingrese el nit (con guiones) (c/f): ";
    getline(cin, nit);

    cout << "Ingrese el genero (M/F): ";
    getline(cin, genero);

    cout << "Ingrese el telefono (sin guiones): ";
    cin >> telefono;
    cin.ignore(); // Ignorar el salto de línea pendiente

    cout << "Ingrese el correo electronico: ";
    getline(cin, correo);

    ostringstream insertQuery;
    insertQuery << "INSERT INTO clientes (nombres, apellidos, nit, genero, telefono, correo_electronico) VALUES ('"
        << nombres << "', '"
        << apellidos << "', '"
        << nit << "', '"
        << genero << "', '"
        << telefono << "', '"
        << correo << "')";

    string insert = insertQuery.str();
    const char* i = insert.c_str();

    int q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Ingreso de cliente Exitoso..." << endl;
    }
    else {
        cout << "**** Error al ingresar cliente *** " << endl;
    }
}
void agregarEmpleado(MYSQL* conectar) {
    string nombres, apellidos, direccion, genero, fechaN, idPuesto,dpi,fechaIL,fechaIng;
    int telefono;
    cout << "===== REGISTRO DE NUEVO EMPLEADO =====" << endl << endl;

    cout << "Ingrese los nombres: ";
    getline(cin, nombres);

    cout << "Ingrese los apellidos: ";
    getline(cin, apellidos);

    cout << "Ingrese la direccion completa: ";
    getline(cin, direccion);

    cout << "Ingrese el telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese el numero de DPI: (sin espacios): ";
    getline(cin, dpi);
    cout << "Ingrese el genero (M/F): ";
    getline(cin, genero);

    cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
    getline(cin, fechaN);

    cout << "***** VERIFIQUE EL PUESTO *****" <<endl;
    cout << "-------------------- "<<endl;
    mostrarPuestos(conectar);
    cout << "-------------------- "<< endl;
    cout << "Ingrese el ID del puesto: " ;
    getline(cin, idPuesto);

    cout << "Ingrese la fecha de inicio de labores (YYYY-MM-DD): ";
    getline(cin, fechaIL);

    cout << "Ingrese la fecha de Ingreso (YYYY-MM-DD): ";
    getline(cin, fechaIng);
    
    cin.ignore(); // Ignorar el salto de línea pendiente

    ostringstream insertQuery;
    insertQuery << "INSERT INTO empleados (nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fechaingreso) VALUES ('"
        << nombres << "', '"
        << apellidos << "', '"
        << direccion << "', '"
        << telefono << "', '"
        <<  dpi << "', '"
        << genero << "', '"
        << fechaN << "', '"
        << idPuesto << "', '"
        << fechaIL << "', '"
        << fechaIng << "')";

    string insert = insertQuery.str();
    const char* i = insert.c_str();

    int q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Ingreso de empleado Exitoso..." << endl;
    }
    else {
        cout << "**** Error al ingresar empleado *** " << endl;
        mostrarError(conectar);
    }
}

void mostrarEmpleados(MYSQL* conectar) {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    string consulta = "SELECT * FROM empleados";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        cout << "Lista de empleados:" << endl;
        cout << "ID" << " , " << "NOMBRES" << " , " << "APELLIDOS" << " , " << "PUESTO" << " , " << "FECHA INGRESO" << endl;
        while ((fila = mysql_fetch_row(resultado))) {
            // Asegúrate de mostrar todas las columnas

            cout << (fila[0] ? fila[0] : "NULL") << ", "
                << (fila[1] ? fila[1] : "NULL") << ", "
                << (fila[2] ? fila[2] : "NULL") << ", "
                << (fila[8] ? fila[8] : "NULL") << ", "
                << (fila[10] ? fila[10] : "NULL") << endl;
        }
        mysql_free_result(resultado);  // Liberar la memoria del resultado
    }
    else {
        cout << "Error al consultar" << endl;
    }
}

void editarEmpleado(MYSQL* conectar) {
    int id;
    cin.ignore();
    string n_nombres, n_apellidos, n_direccion, n_genero, n_fechaN, n_idPuesto, n_fechaIL, n_fechaIng;
    int n_telefono;
    int n_dpi;
    cout << "Ingrese el ID del empleado a editar: ";
    cin >> id;
    cout << "Ingrese los nuevos nombres: ";
    getline(cin, n_nombres);
    cout << "Ingrese los nuevos apellidos: ";
    getline(cin, n_apellidos);
    cout << "Ingrese la nueva direccion: ";
    getline(cin, n_direccion);
    cout << "Ingrese el nuevo telefono";
        cin >> n_telefono;
    cin.ignore(); // Limpiar el buffer
    cout << "Ingrese el nuevo DPI";
        cin >> n_dpi;
        cin.ignore(); // Limpiar el buffer
    cout << "Ingrese el nuevo genero: ";
    getline(cin, n_genero);
    cout << "Ingrese  la nueva fecha de nacimiento: ";
    getline(cin, n_fechaN);
    cout << "Ingrese el nuevo id Puesto: ";
    getline(cin, n_idPuesto);
    cout << "Ingrese la nueva fecha de Inicio de labores: ";
    getline(cin, n_fechaIL);
    cout << "Ingrese la nueva fecha de ingreso: ";
    getline(cin, n_fechaIng);

    string update = "UPDATE empleados SET nombres = '" + n_nombres +
        "', apellidos = '" + n_apellidos +
        "', direccion = '" + n_direccion +
        "', telefono = " + to_string(n_telefono) +
        ", dpi = " + to_string(n_dpi) +
        ", genero = '" + n_genero +
        "', fecha_nacimiento = '" + n_fechaN +
        "', id_puesto = " + n_idPuesto +
        ", fecha_inicio_labores = '" + n_fechaIL +
        "', fecha_ingreso = '" + n_fechaIng +
        "' WHERE id = " + to_string(id);

    const char* u = update.c_str();
    int q_estado = mysql_query(conectar, u);

    if (!q_estado) {
        cout << "Actualización Exitosa..." << endl;
    }
    else {
        cout << "**** Error al actualizar **** " << endl;
        mostrarError(conectar);
    }
}

void mostrarCliente(MYSQL* conectar) {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    string consulta = "SELECT * FROM clientes";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        cout << "Lista de clientes:" << endl;
        cout << "ID" << " , " << "NOMBRES" << " , " << "APELLIDOS" << " , " << "NIT" << " , " << "GENERO" << " , " << "TELEFONO" << " , " << "CORREO" << " , " << endl;
        while ((fila = mysql_fetch_row(resultado))) {
            // Asegúrate de mostrar todas las columnas
     
            cout << (fila[0] ? fila[0] : "NULL") << ", "
                <<  (fila[1] ? fila[1] : "NULL") << ", "
                <<  (fila[2] ? fila[2] : "NULL") << ", "
                <<  (fila[3] ? fila[3] : "NULL") << ", "
                <<  (fila[4] ? fila[4] : "NULL") << ", "
                <<  (fila[5] ? fila[5] : "NULL") << ", "
                <<  (fila[6] ? fila[6] : "NULL") << endl;
        }
        mysql_free_result(resultado);  // Liberar la memoria del resultado
    }
    else {
        cout << "Error al consultar" << endl;
    }
}

void editarPuesto(MYSQL* conectar) {
    int id;
    string nuevoPuesto;
    cout << "Ingrese el ID del puesto a editar: ";
    cin >> id;
    cout << "Ingrese el nuevo nombre del puesto: ";
    cin >> nuevoPuesto;
    string update = "UPDATE puestos SET puesto = '" + nuevoPuesto + "' WHERE idPuesto = " + to_string(id);
    const char* u = update.c_str();
    int q_estado = mysql_query(conectar, u);

    if (!q_estado) {
        cout << "Actualización Exitosa..." << endl;
    }
    else {
        cout << "**** Error al actualizar **** " << endl;
        mostrarError(conectar);
    }
}


void agregarPuesto(MYSQL* conectar) {
    string puesto;
    cout << "Ingrese Puesto: ";
    cin >> puesto;
    string insert = "INSERT INTO puestos(puesto) VALUES('" + puesto + "')";
    const char* i = insert.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Ingreso Exitoso..." << endl;
    }
    else {
        cout << "**** Error al ingresar *** " << endl;
    }
}

void mostrarPuestos(MYSQL* conectar) {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    string consulta = "SELECT * FROM puestos";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        cout << "Lista de Puestos:" << endl;
        while (fila = mysql_fetch_row(resultado)) {
            cout << fila[0] << ". " << fila[1] << endl;
        }
    }
    else {
        cout << "Error al consultar" << endl;
        mostrarError(conectar);
    }
}
void mostrarError(MYSQL* conectar) {
    cout << "Error: " << mysql_error(conectar) << endl;
}

bool validarNIT(const string& nit) {
    // Validar formato NIT: Puede tener guiones y debe tener el formato adecuado
    // Ejemplo de NIT válido: 1234-567890-123-4
    if (nit == "c/f") {
        return true;
    }
    size_t len = nit.length();
    if (len < 9 || len > 17) {
        return false;
    }
    // Validar que contenga solo dígitos o guiones
    for (char c : nit) {
        if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    return true;
}
bool buscarClientePorNIT(MYSQL* conectar, const string& nit, string& nombres, string& apellidos) {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    string consulta = "SELECT nombres, apellidos FROM clientes WHERE nit = '" + nit + "'";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        if ((fila = mysql_fetch_row(resultado))) {
            nombres = fila[0] ? fila[0] : "NULL";
            apellidos = fila[1] ? fila[1] : "NULL";
            mysql_free_result(resultado);
            return true;
        }
        mysql_free_result(resultado);
    }
    else {
        cout << "Error al consultar cliente por NIT." << endl;
        mostrarError(conectar);
    }
    return false;
}

void agregarClienteSiNoExiste(MYSQL* conectar, const string& nit) {
        string nombres, apellidos, genero, correo;
        int telefono;

        if (!validarNIT(nit)) {
            cout << "NIT invalido. Intente de nuevo." << endl;
            return;
        }

        if (buscarClientePorNIT(conectar, nit, nombres, apellidos)) {
            cout << "Cliente encontrado: " << nombres << " " << apellidos << endl;
            return;
        }

        cout << "Cliente no encontrado. Proceda a registrar el nuevo cliente." << endl;
        cout << "Ingrese los nombres: ";
        getline(cin, nombres);

        cout << "Ingrese los apellidos: ";
        getline(cin, apellidos);

        cout << "Ingrese el genero (M/F): ";
        getline(cin, genero);

        cout << "Ingrese el telefono (sin guiones): ";
        cin >> telefono;
        cin.ignore(); // Ignorar el salto de línea pendiente

        cout << "Ingrese el correo electronico: ";
        getline(cin, correo);

        ostringstream insertQuery;
        insertQuery << "INSERT INTO clientes (nombres, apellidos, nit, genero, telefono, correo_electronico) VALUES ('"
            << nombres << "', '"
            << apellidos << "', '"
            << nit << "', '"
            << genero << "', '"
            << telefono << "', '"
            << correo << "')";

        string insert = insertQuery.str();
        const char* i = insert.c_str();

        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso de cliente Exitoso..." << endl;
        }
        else {
            cout << "**** Error al ingresar cliente *** " << endl;
        }
}
void subMenuGestionVentas(MYSQL* conectar) {
    int opcion;
    do {
        cout << "===== SUBMENU GESTION VENTAS =====" << endl;
        cout << "1. Registrar Venta" << endl;
        cout << "2. Mostrar Ventas" << endl;
        cout << "3. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin
        switch (opcion) {
        case 1:
            registrarVenta(conectar);
            break;
        case 2:
            mostrarVentas(conectar);
            break;
        case 3:
            system("cls");
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
}

void registrarVenta(MYSQL* conectar) {
    string nit, nombres, apellidos;

    cout << "Ingrese el NIT del cliente (con guiones) (c/f): ";
    getline(cin, nit);

    agregarClienteSiNoExiste(conectar, nit);

    // Aquí puedes agregar más lógica para registrar la venta
    // Por ejemplo, solicitar detalles de los productos comprados, cantidad, etc.
    cout << "Registro de venta en desarrollo..." << endl;
}

void mostrarVentas(MYSQL* conectar) {
    // Implementar la lógica para mostrar las ventas registradas
    cout << "Mostrar ventas en desarrollo..." << endl;
}

void subMenuProveedores(MYSQL* conectar) {
    int opcion;
    do {
        cout << "===== SUBMENU PROVEEDORES =====" << endl;
        cout << "1. Registrar Proveedor" << endl;
        cout << "2. Mostrar Proveedores" << endl;
        cout << "3. Editar Proveedores" << endl;
        cout << "4. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin
        switch (opcion) {
        case 1:
            agregarProveedor(conectar);
            break;
        case 2:
            mostrarProveedor(conectar);
            break;
        case 3:
            editarProveedor(conectar);
            break;
        case 4:
            system("cls");
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
}

void agregarProveedor(MYSQL* conectar) {
    string proveedor, direccion, telefono, nit;
    cout << "===== REGISTRO DE NUEVO PROVEEDOR =====" << endl << endl;

    cout << "Ingrese el nombre del proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese el nit: ";
    getline(cin, nit);
    cout << "Ingrese la direccion completa: ";
    getline(cin, direccion);
      cout << "Ingrese el telefono: ";
    cin >> telefono;
    cin.ignore();
    ostringstream insertQuery;
    insertQuery << "INSERT INTO proveedores (proveedor, nit, direccion, telefono) VALUES ('"
        << proveedor << "', '"
        << nit << "', '"
        << direccion << "', '"
        << telefono << "')";

    string insert = insertQuery.str();
    const char* i = insert.c_str();

    int q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Ingreso de proveedor Exitoso..." << endl;
    }
    else {
        cout << "**** Error al ingresar proveedor *** " << endl;
    }
}

void mostrarProveedor(MYSQL* conectar) {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    string consulta = "SELECT * FROM proveedores";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        cout << "Lista de Proveedores:" << endl;
        while ((fila = mysql_fetch_row(resultado))) {
            // Asegúrate de mostrar todas las columnas

            cout << (fila[0] ? fila[0] : "NULL") << ", "
                << (fila[1] ? fila[1] : "NULL") << ", "
                << (fila[2] ? fila[2] : "NULL") << ", "
                << (fila[3] ? fila[3] : "NULL") << ", "
                << (fila[4] ? fila[4] : "NULL") << endl;
        }
        mysql_free_result(resultado);  // Liberar la memoria del resultado
    }
    else {
        cout << "Error al consultar" << endl;
        mostrarError(conectar);
    }
}
void editarProveedor(MYSQL * conectar) {
        int id;
        string n_proveedor, n_direccion;
        int n_nit, n_telefono;
        cout << "Ingrese el ID del proveedor a editar: ";
        cin >> id;
        cout << "Ingrese el nuevo nombre del proveedor: ";
        getline(cin, n_proveedor);
        cout << "Ingrese el nuevo nit del proveedor: ";
        cin >> n_nit;
        cin.ignore();
        cout << "Ingrese la nueva direccion del proveedor: ";
        getline(cin, n_direccion);
        cout << "Ingrese el nuevo telefono del proveedor: ";
        cin >> n_telefono;
        cin.ignore();

        string update = "UPDATE proveedores SET proveedor = '" + n_proveedor +
            "', nit = " + to_string(n_nit) +
            ", direccion = '" + n_direccion +
            "', telefono = " + to_string(n_telefono) +
            " WHERE id = " + to_string(id);


        const char* u = update.c_str();
        int q_estado = mysql_query(conectar, u);
        if (!q_estado) {
            cout << "Actualización Exitosa..." << endl;
        }
        else {
            cout << "**** Error al actualizar **** " << endl;
        }
    }
void subMenuProductos(MYSQL* conectar) {
    int opcion;
    do {
        cout << "===== SUBMENU PRODUCTOS =====" << endl;
        cout << "1. Registrar Productos" << endl;
        cout << "2. Registrar Marcas" << endl;
        cout << "3. Buscar Marcas" << endl;
        cout << "4. Editar Productos" << endl;
        cout << "5. Mostrar Productos" << endl;
        cout << "6. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin
        switch (opcion) {
        case 1:
            agregarProductos(conectar);
            break;
        case 2:
            agregarMarca(conectar);
            break;
        case 3:
            mostrarMarca(conectar);
            break;
        case 4:
            editarProducto(conectar);
            break;
        case 5:
            mostrarProducto(conectar);
            break;
        case 6:
            system("cls");
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);
}
 void agregarProductos(MYSQL* conectar) {
        string producto, Descripcion, fechaIng;
        int idMarca;
        int existencia;
        double precioCosto;
        double precioVenta;
        cout << "===== REGISTRO DE INGRESO PRODUCTO =====" << endl << endl;

        cout << "Ingrese el nombre del producto: ";
        getline(cin, producto);

        cout << "Ingrese el id de Marca: ";
        cin >> idMarca;
        cin.ignore();
        cout << "Ingrese la Descripcion del producto: ";
        getline(cin, Descripcion);
        cout << "Ingrese el precio de Costo: ";
        cin >> precioCosto;
        cin.ignore();
        cout << "Ingrese el precio de Venta: ";
        cin >> precioVenta;
        cin.ignore();
        cout << "Ingrese la cantidad de existencia: ";
        cin >> existencia;
        cin.ignore();
        cout << "Ingrese la fecha del ingreso: ";
        getline(cin, fechaIng);
        cin.ignore();

        ostringstream insertQuery;
        insertQuery << "INSERT INTO productos (producto, idMarca, Descripcion, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES ('"
            << producto << "', '"
            << idMarca << "', '"
            << Descripcion << "', '"
            << precioCosto << "', '"
            << precioVenta << "', '"
            << existencia << "', '"
            << fechaIng << "')";

        string insert = insertQuery.str();
        const char* i = insert.c_str();

        int q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso de producto Exitoso..." << endl;
        }
        else {
            cout << "**** Error al ingresar producto *** " << endl;
            mostrarError(conectar);
        }
    }

void editarProducto(MYSQL* conectar) {
        int idProducto;
        string producto, Descripcion, fechaIng;
        int idMarca;
        int existencia;
        double precioCosto;
        double precioVenta;

        cout << "===== ACTUALIZACIÓN DE PRODUCTO =====" << endl << endl;

        cout << "Ingrese el ID del producto a actualizar: ";
        cin >> idProducto;
        cin.ignore();

        cout << "Ingrese el nombre del producto: ";
        getline(cin, producto);

        cout << "Ingrese el id de Marca: ";
        cin >> idMarca;
        cin.ignore();
        cout << "Ingrese la Descripcion del producto: ";
        getline(cin, Descripcion);
        cout << "Ingrese el precio de Costo: ";
        cin >> precioCosto;
        cin.ignore();
        cout << "Ingrese el precio de Venta: ";
        cin >> precioVenta;
        cin.ignore();
        cout << "Ingrese la cantidad de existencia: ";
        cin >> existencia;
        cin.ignore();
        cout << "Ingrese la fecha del ingreso: ";
        getline(cin, fechaIng);
        cin.ignore();

        ostringstream updateQuery;
        updateQuery << "UPDATE productos SET "
            << "producto='" << producto << "', "
            << "idMarca='" << idMarca << "', "
            << "Descripcion='" << Descripcion << "', "
            << "precio_costo='" << precioCosto << "', "
            << "precio_venta='" << precioVenta << "', "
            << "existencia='" << existencia << "', "
            << "fecha_ingreso='" << fechaIng << "' "
            << "WHERE idProducto='" << idProducto << "'";

        string query = updateQuery.str();
        const char* q = query.c_str();

        if (mysql_query(conectar, q)) {
            cerr << "Error al actualizar el producto: " << mysql_error(conectar) << endl;
        }
        else {
            cout << "Producto actualizado exitosamente." << endl;
        }
    }
void mostrarProducto(MYSQL* conectar) {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    string consulta = "SELECT * FROM productos";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        cout << "Lista de Productos:" << endl;
        while ((fila = mysql_fetch_row(resultado))) {
            // Asegúrate de mostrar todas las columnas

            cout << (fila[0] ? fila[0] : "NULL") << ", "
                << (fila[1] ? fila[1] : "NULL") << ", "
                << (fila[2] ? fila[2] : "NULL") << ", "
                << (fila[3] ? fila[3] : "NULL") << ", "
                << (fila[5] ? fila[5] : "NULL") << ", "
                << (fila[6] ? fila[6] : "NULL") << ", "
                << (fila[7] ? fila[7] : "NULL") << ", "
                << (fila[8] ? fila[8] : "NULL") << endl;
        }
        mysql_free_result(resultado);  // Liberar la memoria del resultado
    }
    else {
        cout << "Error al consultar" << endl;
        mostrarError(conectar);
    }
}
void agregarMarca(MYSQL* conectar) {
    string marca;
    cout << "Ingrese la Marca: ";
    cin >> marca;
    string insert = "INSERT INTO marcas(marcas) VALUES('" + marca + "')";
    const char* i = insert.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Ingreso Exitoso..." << endl;
    }
    else {
        cout << "**** Error al ingresar *** " << endl;
    }
}
void mostrarMarca(MYSQL* conectar) {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    string consulta = "SELECT * FROM marcas";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        cout << "Lista de Marcas:" << endl;
        while (fila = mysql_fetch_row(resultado)) {
            cout << fila[0] << ". " << fila[1] << endl;
        }
    }
    else {
        cout << "Error al consultar" << endl;
        mostrarError(conectar);
    }
}