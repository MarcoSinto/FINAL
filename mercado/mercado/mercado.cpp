/*#include <mysql.h>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int q_estado;

void agregarPuesto(MYSQL* conectar);
void mostrarPuestos(MYSQL* conectar);
void agregarCliente(MYSQL* conectar);
void mostrarError(MYSQL* conectar);
void mostarClientes(MYSQL* conectar);
void subMenuAdmin(MYSQL* conectar);
void subMenuGestionClientes(MYSQL* conectar);

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

            switch (opcion) {
            case 1:
                subMenuAdmin(conectar);
                break;
            case 2:
                subMenuGestionClientes(conectar);
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
            }
        } while (opcion != 3);
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
        cout << "===== SUBMENÚ ADMIN =====" << endl;
        cout << "1. PUESTOS" << endl;
        cout << "2. VER COMPRAS" << endl;
        cout << "3. ADMIN l" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin

        switch (opcion) {
        case 1:
            agregarPuesto(conectar);
            break;
        case 2:
            mostrarPuestos(conectar);
            break;
        case 3:
            // Regresar al menú principal
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
}
void subMenuGestionClientes(MYSQL* conectar) {
    int opcion;
    do {
        cout << "===== SUBMENÚ GESTION CLIENTES =====" << endl;
        cout << "1. Agregar Cliente" << endl;
        cout << "2. Mostrar Clientes" << endl;
        cout << "3. Regresar al menú principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin

        switch (opcion) {
        case 1:
            agregarCliente(conectar);
            break;
        case 2:
            mostrarClientes(conectar);
            break;
        case 3:
            // Regresar al menú principal
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
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
        cout << "===== Ingreso de cliente Exitoso... =====" << endl;
    }
    else {
        cout << "XXXXX Error al ingresar cliente XXXXX " << endl;
        mostrarError(conectar);
    }
}







*/

//prueba
#include <mysql.h>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int q_estado;

void agregarPuesto(MYSQL* conectar);
void mostrarPuestos(MYSQL* conectar);
void agregarCliente(MYSQL* conectar);
void mostrarError(MYSQL* conectar);
void mostrarCliente(MYSQL* conectar);
void subMenuAdmin(MYSQL* conectar);
void subMenuGestionClientes(MYSQL* conectar);
void subMenuGestionVentas(MYSQL* conectar);
void registrarVenta(MYSQL* conectar);
void mostrarVentas(MYSQL* conectar);



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
        cout << "1. Agregar Puesto" << endl;
        cout << "2. Mostrar Puestos" << endl;
        cout << "3. Regresar al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea pendiente después de cin
        system("cls");
        switch (opcion) {
        case 1:
            agregarPuesto(conectar);
            break;
        case 2:
            mostrarPuestos(conectar);
            break;
        case 3:
            // Regresar al menú principal
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
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
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
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
