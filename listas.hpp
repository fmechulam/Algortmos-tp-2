#ifndef LISTAS_HPP_INCLUDED
#define LISTAS_HPP_INCLUDED

template <typename T> struct Nodo {
	T dato; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
	Nodo<T>* ult; // puntero al ultimo
};

template <typename T> void push(Nodo<T>* &pila, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = pila;
	if (pila == nullptr){
		nuevo->ult = nuevo;
	}
	else {
		nuevo->ult = pila->ult;
	}	
	pila = nuevo;
}

template <typename T> T pop(Nodo<T>* &pila)
{
	if (pila == nullptr) {
		std::cout << "Error: pop en pila vacia" << std::endl;
		exit(EXIT_FAILURE);
		//modo no recomendado de terminar, en particular si uso objetos
	}
	T valor = pila->dato;
	Nodo<T>* aux_elim = pila;
	pila = pila->sig;
	if(pila != nullptr){
	pila->ult = aux_elim->ult;
	}
	delete aux_elim;
	return valor;
}

template <typename T> void agregar(Nodo<T>*& cola, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	if (cola == nullptr) {
		cola = nuevo;
	} else {
		cola->ult->sig = nuevo;
	}
	cola->ult = nuevo;
}

#endif // LISTAS_HPP_INCLUDED