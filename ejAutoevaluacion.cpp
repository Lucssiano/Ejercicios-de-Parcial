#include <iostream>

#define cantCursos 3
#define meses 6

using namespace std;

struct Curso
{
  int cod, cupo;
  string nombre;
};

void ingresoDeCursos(Curso v[], int cant);
void inicializarM(int mat[cantCursos][meses], int cf, int cc);
void ingresoDeInscripciones(Curso v[], int mat[cantCursos][meses], int cant);
int secuencial(Curso v[], unsigned t, int bus);
void punto1(int mat[cantCursos][meses], int cf, int cc);
void punto2(Curso v[], int mat[cantCursos][meses], int cf, int cc);

int main()
{
  Curso vecCursos[cantCursos];
  int inscripciones[cantCursos][meses];
  ingresoDeCursos(vecCursos, cantCursos);
  inicializarM(inscripciones, cantCursos, meses);
  ingresoDeInscripciones(vecCursos, inscripciones, cantCursos);
  punto1(inscripciones, cantCursos, meses);
  punto2(vecCursos, inscripciones, cantCursos, meses);
  return 0;
}

void ingresoDeCursos(Curso v[], int cant)
{
  for (int i = 0; i < cant; i++)
  {
    cout << "Ingrese el codigo del curso " << i + 1 << ": ";
    cin >> v[i].cod;
    cout << "Ingrese el nombre del curso " << i + 1 << ": ";
    cin >> v[i].nombre;
    cout << "Ingrese el cupo del curso " << i + 1 << ": ";
    cin >> v[i].cupo;
  }
}

void inicializarM(int mat[cantCursos][meses], int cf, int cc)
{
  for (int i = 0; i < cf; i++)
    for (int j = 0; j < cc; j++)
      mat[i][j] = 0;
}

void ingresoDeInscripciones(Curso v[], int mat[cantCursos][meses], int cant)
{
  int cod, pos, mes;

  cout << "Ingrese el codigo del curso al que quiere inscribirse: ";
  cin >> cod;

  while (cod != 0)
  {
    pos = secuencial(v, cant, cod);

    while (pos == -1)
    {
      cout << "El codigo del curso al que se quiere inscribir no existe " << endl;
      cout << "Ingrese el codigo del curso al que quiere inscribirse: ";
      cin >> cod;
      pos = secuencial(v, cant, cod);
    }

    cout << "Ingrese el mes en el que quiere realizar el curso (7 a 12): ";
    cin >> mes;

    // while (mes < 7 || mes > 12)
    // {
    //   cout << "Ingrese el mes en el que quiere realizar el curso (7 a 12): ";
    //   cin >> mes;
    // }

    if (mat[pos][mes - 7] < v[pos].cupo)
      mat[pos][mes - 7]++;
    else
      cout << "Inscripcion rechazada por falta de cupo" << endl;

    cout << "Ingrese el codigo del curso al que quiere inscribirse: ";
    cin >> cod;
  }
}

void punto1(int mat[cantCursos][meses], int cf, int cc)
{
  for (int i = 0; i < cf; i++)
  {
    int inscriptosPorCurso = 0;
    cout << "Inscriptos del curso " << i + 1 << ":" << endl;
    for (int j = 0; j < cc; j++)
    {
      inscriptosPorCurso += mat[i][j];
    }
    cout << inscriptosPorCurso << endl;
  }

  for (int i = 0; i < cc; i++)
  {
    int inscriptosPorMes = 0;
    cout << "Inscriptos del mes " << i + 7 << ":" << endl;
    for (int j = 0; j < cf; j++)
      inscriptosPorMes += mat[j][i];
    cout << inscriptosPorMes << endl;
  }
}

void punto2(Curso v[], int mat[cantCursos][meses], int cf, int cc)
{
  for (int i = 0; i < cf; i++)
  {
    int inscriptosTotales = 0;
    for (int j = 0; j < cc; j++)
      inscriptosTotales += mat[i][j];
    cout << "Codigo de curso: " << v[i].cod << " Cantidad total de inscriptos: " << inscriptosTotales;
  }
}

int secuencial(Curso v[], unsigned t, int bus)
{
  unsigned i = 0;
  while (i < t && v[i].cod != bus)
    i++;
  if (i == t)
    return -1;
  else
    return i;
}