#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;
    bool activa;
    int intentosFallidos;
    int mesesInactivos;

public:
    // Constructor por defecto
    CuentaBancaria() {
        titular = "Desconocido";
        saldo = 1000.0;  // Saldo inicial de 1000
        activa = true;
        intentosFallidos = 0;
        mesesInactivos = 0;
    }

    // Constructor con parámetros
    CuentaBancaria(string t) {
        titular = t;
        saldo = 1000.0;  // Saldo fijo de 1000
        activa = true;
        intentosFallidos = 0;
        mesesInactivos = 0;
    }

    // Método para depositar dinero
    void depositar(double monto) {
        if (!activa) {
            cout << "Cuenta bloqueada. No se puede realizar el deposito." << endl;
            return;
        }
        if (monto <= 0) {
            cout << "No se puede depositar un monto negativo o cero." << endl;
            return;
        }
        saldo += monto;
        cout << "Deposito exitoso. Nuevo saldo: " << saldo << endl;
    }

    // Método para retirar dinero
    void retirar(double monto) {
        if (!activa) {
            cout << "Cuenta bloqueada. No se puede realizar el retiro." << endl;
            return;
        }
        if (monto <= 0) {
            cout << "No se puede retirar un monto negativo o cero." << endl;
            return;
        }
        if (monto > saldo) {
            cout << "Saldo insuficiente." << endl;
            intentosFallidos++;
            if (intentosFallidos >= 3) {
                activa = false;
                cout << "La cuenta ha sido bloqueada por 3 intentos fallidos." << endl;
            }
            return;
        }
        saldo -= monto;
        if (saldo < 100) {
            cout << "Advertencia: el saldo es inferior a 100." << endl;
        }
        cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
    }

    // Método para consultar el saldo
    void consultarSaldo() {
        if (!activa) {
            cout << "Cuenta bloqueada. No se puede consultar el saldo." << endl;
            return;
        }
        cout << "El saldo actual es: " << saldo << endl;
    }

    // Método para simular inactividad por meses
    void simularInactividad(int meses) {
        mesesInactivos += meses;
        if (mesesInactivos >= 6) {
            activa = false;
            cout << "La cuenta ha sido bloqueada por inactividad." << endl;
        }
    }

    // Método para obtener el estado de la cuenta (activa o bloqueada)
    bool estaActiva() {
        return activa;
    }

    // Método para obtener el nombre del titular
    string getTitular() {
        return titular;
    }
};

int main() {
    // Crear 30 cuentas bancarias con nombres ficticios
    CuentaBancaria cuentas[30] = {
        CuentaBancaria("Daniela"),
        CuentaBancaria("Maria"),
        CuentaBancaria("Carlos"),
        CuentaBancaria("Karla"),
        CuentaBancaria("Luis"),
        CuentaBancaria("Jose"),
        CuentaBancaria("Pedro"),
        CuentaBancaria("Isabel"),
        CuentaBancaria("Javier"),
        CuentaBancaria("Laura"),
        CuentaBancaria("Alfredo"),
        CuentaBancaria("Eva"),
        CuentaBancaria("Miguel"),
        CuentaBancaria("Efren"),
        CuentaBancaria("Roberto"),
        CuentaBancaria("Lucia"),
        CuentaBancaria("Ricardo"),
        CuentaBancaria("Mariana"),
        CuentaBancaria("David"),
        CuentaBancaria("Carmen"),
        CuentaBancaria("Hector"),
        CuentaBancaria("Patricia"),
        CuentaBancaria("Raul"),
        CuentaBancaria("Marta"),
        CuentaBancaria("Felipe"),
        CuentaBancaria("Raquel"),
        CuentaBancaria("Daniel"),
        CuentaBancaria("Adriana"),
        CuentaBancaria("Francisco"),
        CuentaBancaria("Nuria"),

    };

    int opcion, cuentaSeleccionada;
    double monto;

    do {
        cout << "\n--- Menu ---\n";
        cout << "Seleccione la cuenta (1-30): ";
        cin >> cuentaSeleccionada;

        if (cuentaSeleccionada < 1 || cuentaSeleccionada > 30) {
            cout << "Selección inválida. Intente de nuevo.\n";
            continue;
        }

        CuentaBancaria& cuenta = cuentas[cuentaSeleccionada - 1];  // Seleccionamos la cuenta correspondiente

        cout << "\nMenu de operaciones para la cuenta de " << cuenta.getTitular() << ":\n";
        cout << "1. Depositar\n";
        cout << "2. Retirar\n";
        cout << "3. Consultar saldo\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el monto a depositar: ";
            cin >> monto;
            cuenta.depositar(monto);
            break;
        case 2:
            cout << "Ingrese el monto a retirar: ";
            cin >> monto;
            cuenta.retirar(monto);
            break;
        case 3:
            cuenta.consultarSaldo();
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 4);

    return 0;
}
