#include <stdio.h>
#include <stdlib.h>

typedef struct {
 double real;
 double imag;
} complex;

typedef struct {

} vector;

complex* add(complex *x, complex *y) {
	complex *tmp = malloc(sizeof(complex));
	tmp->real = x->real + y->real ;
	tmp->imag = x->imag + y->imag;

	return tmp;
}

complex* subtract(complex *x, complex *y) {
	complex *tmp = malloc(sizeof(complex));
	tmp->real = x->real - y->real;
	tmp->imag = x->imag - y->imag;

	return tmp;
}

complex* multiplikate(complex *x, complex *y) {
	complex *tmp = malloc(sizeof(complex));
	tmp->real = (x->real * y->real) - (x->imag * y->imag);
	tmp->imag = (x->real * y->imag) + (x->imag * y->real);

	return tmp;
}

complex* division(complex *x, complex *y) {
	complex *tmp = malloc(sizeof(complex));
	tmp->real = ( (x->real * y->real) + (x->imag * y->imag) )/( (y->real * y-> real) + (y->imag * y->imag)  );
	tmp->imag = ( (x->imag * y->real)-(x->real * y->imag)  )/( (y->real * y->real)  + (y->imag * y->imag)  );

	return tmp;
}

complex* conjungation(complex *x) {
	complex *tmp = malloc(sizeof(complex));
	tmp->real = x->real;
	tmp->imag = (-1)*x->imag;

	return tmp;
}

int main() {

puts("\nHello world\n");

}
