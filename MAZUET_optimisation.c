#include <math.h>
#include <stdlib.h>

float fonction(float a, float b, float c, float d, float e, float f, float x,
               float y);

int main() {
  float a, b, c, d, e, f, xmin, xmax, ymin, ymax; // initialisation des
                                                  // variables
  int n;
  long int u;
  time(&u);
  srand(u);

  printf("choix de a : ");
  scanf("%f", &a);
  printf("choix de b : ");
  scanf("%f", &b);
  printf("choix de c : ");
  scanf("%f", &c);
  printf("choix de d : ");
  scanf("%f", &d);
  printf("choix de e : ");
  scanf("%f", &e);
  printf("choix de f : ");
  scanf("%f", &f);

  printf("choix de xmin : ");
  scanf("%f", &xmin);
  printf("choix de xmax : ");
  scanf("%f", &xmax);
  while (xmin > xmax) {
    printf("bornes de x non conformes ! xmin<=xmax\n");
    printf("choix de xmin : ");
    scanf("%f", &xmin);
    printf("choix de xmax : ");
    scanf("%f", &xmax);
  }

  printf("choix de ymin : ");
  scanf("%f", &ymin);
  printf("choix de ymax : ");
  scanf("%f", &ymax);
  while (ymin > ymax) {
    printf("bornes de y non conformes ! ymin<=ymax\n");
    printf("choix de ymin : ");
    scanf("%f", &ymin);
    printf("choix de ymax : ");
    scanf("%f", &ymax);
  }

  printf("Optimisation de la fonction f(x,y)=%.3fx^2+%.3fy^2+%.3fxy+%.3fx+%.3fy+%.3f\n",a, b, c, d, e, f); // faciliter la compréhension en limitant le nombre de chiffres après la virgule

  printf("nombre de répétition (0<n<=100000) : "); // maximum choisis
                                                   // arbitrairement
  scanf("%d", &n);
  while (n < 0 || n > 100000) {
    printf(
        "nombre de répétition trop important ! entrer n (0<n<=100000) : "); // maximum choisis arbitrairement
    scanf("%d", &n);
  }

  float x_optimise, y_optimise, f_optimise; // plus petite valeur f(x,y)
  x_optimise = xmin + (float)rand() / ((float)RAND_MAX / (xmax - xmin));
  y_optimise = ymin + (float)rand() / ((float)RAND_MAX / (ymax - ymin));
  f_optimise = fonction(a, b, c, d, e, f, x_optimise, y_optimise);
  if (n <= 20)
    printf("f(%f,%f)=%f\n", x_optimise, y_optimise, f_optimise);

  for (int i = 1; i < n; i++) {

    float x2, y2;
    x2 = xmin + (float)rand() / ((float)RAND_MAX / (xmax - xmin));

    y2 = ymin + (float)rand() / ((float)RAND_MAX / (ymax - ymin));

    float f2 = fonction(a, b, c, d, e, f, x2, y2);
    if (f2 < f_optimise) {
      x_optimise = x2;
      y_optimise = y2;
      f_optimise = f2;
    }
    if (n <= 20)
      printf("f(%f,%f)=%f\n", x2, y2, f2);
  }
  printf("le couple pour lequel la fonction est la plus optimale est (%f,%f)",
         x_optimise, y_optimise);
}

float fonction(float a, float b, float c, float d, float e, float f, float x,
               float y) {
  return a * pow(x, 2) + b * pow(y, 2) + c * x * y + d * x + e * y + f;
}