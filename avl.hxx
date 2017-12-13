#include "avl.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
//************************************* * * Seccion const_reverse_Iterator * * *************************************************
template <typename T , class comparar  >
AVL<T,comparar>::const_reverse_iterator:: const_reverse_iterator(){
	nodo_it = typename bintree<std::pair<T,int> >::const_node();
}
template <typename T , class comparar  >
AVL<T,comparar>::const_reverse_iterator:: const_reverse_iterator(const const_reverse_iterator & it){
	nodo_it = it.nodo_it;
}
template <typename T , class comparar  >
const std::pair<T,int>  & AVL<T,comparar>::const_reverse_iterator::operator*() const{
	return *nodo_it;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::const_reverse_iterator & AVL<T,comparar>::const_reverse_iterator::operator++(){
	  if (nodo_it.null())
	    return *this;

	  if (!nodo_it.left().null()) {
		  nodo_it = nodo_it.left();
	      while (!nodo_it.right().null())
	    	  nodo_it = nodo_it.right();
	  }
	  else {
	      while (!nodo_it.parent().null() &&
	    		  nodo_it.parent().left() == nodo_it)
	    	  nodo_it = nodo_it.parent();
	      // Si (padre de elnodo es nodo_nulo), hemos terminado
	      //       // En caso contrario, el siguiente node es el padre
	      nodo_it = nodo_it.parent();
	  }
	  return *this;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::const_reverse_iterator & AVL<T,comparar>::const_reverse_iterator::operator--(){
	  if (nodo_it.null())
	    return *this;

	  if (!nodo_it.right().null()) {
		  nodo_it = nodo_it.right();
	      while (!nodo_it.left().null())
	    	  nodo_it = nodo_it.left();
	  }
	  else {
	      while (!nodo_it.parent().null() &&
	    		  nodo_it.parent().right() == nodo_it)
	    	  nodo_it = nodo_it.parent();
	      // Si (padre de elnodo es nodo_nulo), hemos terminado
	      //       // En caso contrario, el siguiente node es el padre
	      nodo_it = nodo_it.parent();
	  }
	  return *this;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::const_reverse_iterator & AVL<T,comparar>::const_reverse_iterator::operator=(const_reverse_iterator it){
	nodo_it = it.nodo_it;
	return *this;
}
template <typename T , class comparar  >
bool AVL<T,comparar>::const_reverse_iterator::operator==(const const_reverse_iterator & it){
	return (nodo_it == it.nodo_it);
}
template <typename T , class comparar  >
bool AVL<T,comparar>::const_reverse_iterator::operator!=(const const_reverse_iterator & it){
	return (nodo_it != it.nodo_it);
}
//************************************* * * Seccion rcbegin , rcend * * *************************************************
template <typename T , class comparar  >
typename AVL<T,comparar>::const_reverse_iterator AVL<T,comparar>::rcbegin(){
	typename AVL<T,comparar>::const_reverse_iterator salida;
	salida.nodo_it = el_avl.root();
	while(!( salida.nodo_it.right() ).null()){
		salida.nodo_it = salida.nodo_it.right();

	}
	return salida;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::const_reverse_iterator AVL<T,comparar>::rcend(){
	typename AVL<T,comparar>::const_reverse_iterator salida;
	salida.nodo_it = el_avl.root().parent();
	return salida;
}

//************************************* * * Seccion reverse_Iterator * * *************************************************
template <typename T , class comparar  >
AVL<T,comparar>::reverse_iterator:: reverse_iterator(){
	nodo_it = typename bintree<std::pair<T,int> >::node();
}
template <typename T , class comparar  >
AVL<T,comparar>::reverse_iterator:: reverse_iterator(const reverse_iterator & ite){
	nodo_it = ite.nodo_it;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::reverse_iterator & AVL<T,comparar>::reverse_iterator:: operator--(){
	  if (nodo_it.null())
	    return *this;

	  if (!nodo_it.right().null()) {
		  nodo_it = nodo_it.right();
	      while (!nodo_it.left().null())
	    	  nodo_it = nodo_it.left();
	  }
	  else {
	      while (!nodo_it.parent().null() &&
	    		  nodo_it.parent().right() == nodo_it)
	    	  nodo_it = nodo_it.parent();
	      // Si (padre de elnodo es nodo_nulo), hemos terminado
	      //       // En caso contrario, el siguiente node es el padre
	      nodo_it = nodo_it.parent();
	  }
	  return *this;
}

template <typename T , class comparar  >
typename AVL<T,comparar>::reverse_iterator & AVL<T,comparar>::reverse_iterator:: operator++(){
	  if (nodo_it.null())
	    return *this;

	  if (!nodo_it.left().null()) {
		  nodo_it = nodo_it.left();
	      while (!nodo_it.right().null())
	    	  nodo_it = nodo_it.right();
	  }
	  else {
	      while (!nodo_it.parent().null() &&
	    		  nodo_it.parent().left() == nodo_it)
	    	  nodo_it = nodo_it.parent();
	      // Si (padre de elnodo es nodo_nulo), hemos terminado
	      //       // En caso contrario, el siguiente node es el padre
	      nodo_it = nodo_it.parent();
	  }
	  return *this;
}
template <typename T , class comparar  >
std::pair<T,int> AVL<T,comparar>::reverse_iterator::operator*() const{
	return *nodo_it;
}
template <typename T , class comparar  >
bool AVL<T,comparar>::reverse_iterator::operator==(const reverse_iterator &i) const{
	return (nodo_it == i.nodo_it);
}
template <typename T , class comparar  >
bool  AVL<T,comparar>::reverse_iterator::operator!=(const reverse_iterator &i) const{
	return (nodo_it != i.nodo_it);
}
template <typename T , class comparar  >
typename AVL<T,comparar>::reverse_iterator &  AVL<T,comparar>::reverse_iterator::operator=(const reverse_iterator &i){
	nodo_it = i.nodo_it;
}
//************************************* * * Seccion rbegin() , rend() * * *************************************************
template <typename T , class comparar  >
typename AVL<T,comparar>::reverse_iterator  AVL<T,comparar>::rbegin(){
	typename AVL<T,comparar>::reverse_iterator salida;
	salida.nodo_it = el_avl.root();
	while(!( salida.nodo_it.right() ).null()){
		salida.nodo_it = salida.nodo_it.right();

	}
	return salida;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::reverse_iterator  AVL<T,comparar>::rend(){
	typename AVL<T,comparar>::reverse_iterator salida;
	salida.nodo_it = el_avl.root().parent();
	return salida;
}
//************************************* * * Seccion  const_iterator * * *************************************************
template <typename T , class comparar  >
AVL<T,comparar>::const_iterator:: const_iterator(){
	nodo_it = typename bintree<std::pair<T,int> >::const_node();
}
template <typename T , class comparar  >
AVL<T,comparar>::const_iterator::const_iterator(const const_iterator & it){
	nodo_it = it.nodo_it;
}
template <typename T , class comparar  >
AVL<T,comparar>::const_iterator::const_iterator(const iterator & it){
	nodo_it = it.nodo_it;
}
template <typename T , class comparar  >
const std::pair<T,int> & AVL<T,comparar>::const_iterator:: operator*() const{
	return *nodo_it;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::const_iterator &  AVL<T,comparar>::const_iterator::operator++(){
	  if (nodo_it.null())
	    return *this;

	  if (!nodo_it.right().null()) {
		  nodo_it = nodo_it.right();
	      while (!nodo_it.left().null())
	    	  nodo_it = nodo_it.left();
	  }
	  else {
	      while (!nodo_it.parent().null() &&
	    		  nodo_it.parent().right() == nodo_it)
	    	  nodo_it = nodo_it.parent();
	      // Si (padre de elnodo es nodo_nulo), hemos terminado
	      //       // En caso contrario, el siguiente node es el padre
	      nodo_it = nodo_it.parent();
	  }
	  return *this;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::const_iterator &  AVL<T,comparar>::const_iterator::operator--(){
	  if (nodo_it.null())
	    return *this;

	  if (!nodo_it.left().null()) {
		  nodo_it = nodo_it.left();
	      while (!nodo_it.right().null())
	    	  nodo_it = nodo_it.right();
	  }
	  else {
	      while (!nodo_it.parent().null() &&
	    		  nodo_it.parent().left() == nodo_it)
	    	  nodo_it = nodo_it.parent();
	      // Si (padre de elnodo es nodo_nulo), hemos terminado
	      //       // En caso contrario, el siguiente node es el padre
	      nodo_it = nodo_it.parent();
	  }
	  return *this;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::const_iterator &  AVL<T,comparar>::const_iterator::operator=(const_iterator it){
	nodo_it = it.nodo_it;
	return *this;
}
template <typename T , class comparar  >
bool AVL<T,comparar>::const_iterator::operator==(const const_iterator & it){
	return (this->nodo_it == it.nodo_it);
}
template <typename T , class comparar  >
bool AVL<T,comparar>::const_iterator::operator!=(const const_iterator & it){
	return (this->nodo_it != it.nodo_it);
}
//************************************* * * FIN Seccion const_iterator * * *************************************************

//************************************* * * Seccion cbegin , cend * * *************************************************
template <typename T , class comparar >
typename AVL<T,comparar>::const_iterator AVL<T,comparar>::cbegin(){
	typename AVL<T,comparar>::const_iterator salida;
	salida.nodo_it = el_avl.root();
	while(!( salida.nodo_it.left() ).null()){
		salida.nodo_it = salida.nodo_it.left();

	}
	return salida;
}
template <typename T , class comparar >
typename AVL<T,comparar>::const_iterator AVL<T,comparar>::cend(){
	typename AVL<T,comparar>::const_iterator salida;
	salida.nodo_it = el_avl.root().parent();
	return salida;
}

//************************************* * * Seccion Iterator * * *************************************************
template <typename T , class comparar  >
AVL<T,comparar>::iterator:: iterator(){
	nodo_it = typename bintree<std::pair<T,int> >::node();
}
template <typename T , class comparar  >
AVL<T,comparar>::iterator:: iterator(const iterator & ite){
	nodo_it = ite.nodo_it;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::iterator & AVL<T,comparar>::iterator:: operator--(){
	  if (nodo_it.null())
	    return *this;

	  if (!nodo_it.left().null()) {
		  nodo_it = nodo_it.left();
	      while (!nodo_it.right().null())
	    	  nodo_it = nodo_it.right();
	  }
	  else {
	      while (!nodo_it.parent().null() &&
	    		  nodo_it.parent().left() == nodo_it)
	    	  nodo_it = nodo_it.parent();
	      // Si (padre de elnodo es nodo_nulo), hemos terminado
	      //       // En caso contrario, el siguiente node es el padre
	      nodo_it = nodo_it.parent();
	  }
	  return *this;
}
template <typename T , class comparar  >
typename AVL<T,comparar>::iterator & AVL<T,comparar>::iterator:: operator++(){
	  if (nodo_it.null())
	    return *this;

	  if (!nodo_it.right().null()) {
		  nodo_it = nodo_it.right();
	      while (!nodo_it.left().null())
	    	  nodo_it = nodo_it.left();
	  }
	  else {
	      while (!nodo_it.parent().null() &&
	    		  nodo_it.parent().right() == nodo_it)
	    	  nodo_it = nodo_it.parent();
	      // Si (padre de elnodo es nodo_nulo), hemos terminado
	      //       // En caso contrario, el siguiente node es el padre
	      nodo_it = nodo_it.parent();
	  }
	  return *this;
}
template <typename T , class comparar  >
std::pair<T,int> AVL<T,comparar>::iterator::operator*() const{
	return *nodo_it;
}
template <typename T , class comparar  >
bool AVL<T,comparar>::iterator::operator==(const iterator &i) const{
	return (nodo_it == i.nodo_it);
}
template <typename T , class comparar  >
bool  AVL<T,comparar>::iterator::operator!=(const iterator &i) const{
	return (nodo_it != i.nodo_it);
}
template <typename T , class comparar  >
typename AVL<T,comparar>::iterator &  AVL<T,comparar>::iterator::operator=(const iterator &i){
	nodo_it = i.nodo_it;
	return *this;
}

//************************************* * * * FIN SECCION ITERATOR * * * ****************************************

template <typename T , class comparar >
typename AVL<T,comparar>::iterator  AVL<T,comparar>::begin(){
	typename AVL<T,comparar>::iterator salida;
	salida.nodo_it = el_avl.root();
	while(!( salida.nodo_it.left() ).null()){
		salida.nodo_it = salida.nodo_it.left();

	}
	return salida;
}
template <typename T , class comparar >
typename AVL<T,comparar>::iterator AVL<T,comparar>::end(){
	typename AVL<T,comparar>::iterator salida;
	salida.nodo_it = el_avl.root().parent();
	return salida;
}
template <typename T , class comparar >
void  AVL<T,comparar>::Ajusta_altura(typename bintree<std::pair<T,int> >::node n){
	if(!n.right().null() || !n.left().null()){
		if( !n.right().null() )
		 (*n).second = h( n.right() ) + 1;
		else
		 (*n).second = h( n.left() ) + 1;
	}
	else if( !n.right().null() && !n.left().null() ){
		(*n).second = max( h( n.left() ) , h( n.right() ) ) + 1;
	}
	else{
		(*n).second = 0;
	}
}

template <typename T , class comparar  >
AVL<T,comparar>::AVL(){
	tama = 0;
}
template <typename T , class comparar  >
int AVL<T,comparar>::h(typename bintree<std::pair<T,int> >::const_node  n){
	if(!n.null()){
		return (*n).second;
	}
	else{
		return 0;
	}
}


template <typename T , class comparar  >
int AVL<T,comparar>::h(typename bintree<std::pair<T,int> >::node  n){
	if(!n.null()){
		return (*n).second;
	}
	else{
		return 0;
	}
}
template <typename T , class comparar >
std::pair<typename AVL<T,comparar>::iterator,bool> AVL<T,comparar>::find(T valor){
	  bool encontrado = false;
	  typename bintree<std::pair<T,int> >::node n;
	  std::pair<typename AVL<T,comparar>::iterator,bool> salida;
	  AVL<T,comparar>::iterator itS;
	  n = el_avl.root();

	  while(!encontrado && !n.null()){
		  if((*n).first == valor){
			  encontrado = true;
		  }
		  else if ( cmp((*n).first , valor) ) {
			  n = n.right();
		  }
		  else{
			  n = n.left();
		  }
	  }
	  (itS.nodo_it) = n;
	  salida.first = itS;
	  salida.second = encontrado;
	  return salida;
}
template <typename T , class comparar  >
std::pair<int,int> AVL<T,comparar>::altura_subarboles_dech_izda_de_un_nodo(typename bintree<std::pair<T,int> >::node n){
	int Arbol_altura_derecho , Arbol_altura_izquierdo;
	std::pair<int,int> resultado;
	if(!n.right().null()){
		Arbol_altura_derecho = h(n.right()) + 1 ;
	}
	else{
		Arbol_altura_derecho = 0;
	}
	if(!n.left().null()){
		Arbol_altura_izquierdo = h(n.left()) + 1 ;

	}
	else{
		Arbol_altura_izquierdo = 0;
	}

	resultado.first = Arbol_altura_derecho;
	resultado.second = Arbol_altura_izquierdo;

	return resultado;

}
template <typename T , class comparar  >
bool AVL<T,comparar>::es_balanceado(typename bintree<std::pair<T,int> >::node n){
	bool resultado = true;

	std::pair<int,int> resul_aux = altura_subarboles_dech_izda_de_un_nodo(n);
	if( abs(resul_aux.first - resul_aux.second) > 1){
		resultado = false;
	}
	return resultado;


}
template <typename T , class comparar >
void AVL<T,comparar>::RSD(typename bintree<std::pair<T,int> >::node n){

	bintree<std::pair<T,int> > subarbol_izq_n , subarbol_dech_de_hijo_izq_n , aux , sub_arbol_dech_de_hijo_izq_de_n  ;
	typename bintree<std::pair<T,int> >::node padre_n = n.parent();
	bool se_puede = false;
	if(!n.left().right().null()){
		el_avl.prune_right(n.left(),subarbol_dech_de_hijo_izq_n); //quitar la relacion entre "su hijo izquierdo" y el subarbol derecho de este hijo 'Q'
		se_puede = true;
	}
	el_avl.prune_left(n,subarbol_izq_n); //quitar la relacion entre n y su hijo izquierdo 'P'
	if(se_puede)
		el_avl.insert_left(n,subarbol_dech_de_hijo_izq_n); //enganchar "subarbol_dech_de_hijo_izq_n" como subarbol izq de n

	if(n == el_avl.root()){			//si n es la raiz del el_avl
		aux = el_avl;
		subarbol_izq_n.insert_right(subarbol_izq_n.root() , aux); //insertar como subarbol derecho el arbol lo que su raiz es n "en este caso es el_avl" ,																//al subarbol izquierdo
		el_avl.assign_subtree(subarbol_izq_n,subarbol_izq_n.root());					//poner como raiz al arbol resultante , el hijo izquierda de n
	}
	else if(n == ( n.parent() ).right() ){ //si el nodo n es el hijo derecho de su padre
		bintree<std::pair<T,int> > aux;
		el_avl.prune_right(n.parent(),aux); //quitamos y guardamos el subarbol derecho del padre de n

		//insertar 'aux' como rama derecha del subarbol izquierdo de n
		subarbol_izq_n.insert_right(subarbol_izq_n.root() , aux);

		//insertar el subarbol izquierdo de n como subarbol derecho del padre de n en el avl
		el_avl.insert_right(padre_n,subarbol_izq_n);
	}
	else{ //si el nodo n es el hijo izquierdo de su padre
		bintree<std::pair<T,int> > aux;

		//quitamos y guardamos el subarbol izquierdo del padre de n
		el_avl.prune_left(n.parent(),aux);

		//insertar 'aux' como rama derecha del subarbol izquierdo de n
		subarbol_izq_n.insert_right(subarbol_izq_n.root() , aux);

		//insertar el subarbol izquierdo de n como subarbol izquierdo del padre de n en el avl
		el_avl.insert_left(padre_n,subarbol_izq_n);
	}

	//************************************************* Ajustar la altura ********************************************************************
	Ajusta_altura(n); //ajustar el nodo de desequilibrio , porque se cambiaba su lugar
	if(!n.right().null())
		Ajusta_altura(n.right());
	if(!n.parent().null()){ //ajustar el nodo padre (nuevo) de n
		Ajusta_altura(n.parent());
	if(!n.parent().parent().null())
		Ajusta_altura(n.parent().parent());
	}
}
template <typename T , class comparar >
void AVL<T,comparar>::RSI(typename bintree<std::pair<T,int> >::node  n){
	bintree<std::pair<T,int> > subarbol_dech_n , subarbol_izq_de_hijo_decha_n , aux ;
	typename bintree<std::pair<T,int> >::node padre_de_n = n.parent();

	bool se_puede = false;
	if(!n.right().left().null()){ //si el hijo izquierdo del hijo derecho de n NO es nulo

		//quitar y guardar el subarbol izquierdr del hijo derecho de n
		el_avl.prune_left(n.right(),subarbol_izq_de_hijo_decha_n);
		se_puede = true;
	}

	//quitar y guardar el subarbol derecho de n
	el_avl.prune_right(n,subarbol_dech_n);

	if(se_puede){ //si el subarbol izquierdo del hijo derecho de n No es nulo

		//insertar el subarbol izquierdo del hijo derecho de n como subarbol derecho de n
		el_avl.insert_right(n,subarbol_izq_de_hijo_decha_n);
	}
	if( n == el_avl.root() ){ // si n es la raiz
		aux = el_avl;

		//insertar aux como subarbol izquierdo del subarbol derecho de n "ANTERIORMENTE"
		subarbol_dech_n.insert_left(subarbol_dech_n.root(),aux);

		//LUEGO ASIGNAMOS EL SUBARBOL DERECHO DE n "ANTERIORMENTE" a avl
		el_avl.assign_subtree(subarbol_dech_n,subarbol_dech_n.root());

		}
		else if( n == ( n.parent() ).right() ){ //si n es el hijo derecho de su padre

			//quitamos y guardamos el subarbol derecho de n  en aux
			el_avl.prune_right(n.parent(),aux);

			//insertamos aux com subarbol izquierdo de la raiz del subarbol derecho de n "Anteriormente"
			subarbol_dech_n.insert_left(subarbol_dech_n.root(),aux);

			//insertamos el subarbol derecho de n "ANTERIORMENTE" en el avl como subarbo derecho del padre de n
			el_avl.insert_right(padre_de_n,subarbol_dech_n);

		}
		else{//si n es el hijo izquierdo de su padre

			//quitamos y guardamos el subarbol izquierdo del padre de n en el avl en aux
			el_avl.prune_left(padre_de_n,aux);

			//insertar aux como subarbol izquierdo de la raiz del subarbol derecho de n "ANTERIORMENTE"
			subarbol_dech_n.insert_left(subarbol_dech_n.root(), aux);

			//insertar el subarbol derecho de n "ANTERIORMENTE" como subarbol izquierdo del padre de n en el avl
			el_avl.insert_left(padre_de_n,subarbol_dech_n);
		}

	Ajusta_altura(n); //ajustar el nodo de desequilibrio , porque se cambiaba su lugar
	if(!n.left().null())
		Ajusta_altura(n.left());
	if(!n.parent().null()){ //ajustar el nodo padre (nuevo) de n
		Ajusta_altura(n.parent());
	if(!n.parent().parent().null())
		Ajusta_altura(n.parent().parent());

	}
}
template <typename T , class comparar >
void AVL<T,comparar>::RDID(typename bintree<std::pair<T,int> >::node  n){
	typename bintree<std::pair<T,int> >::node node_aux = n;
	RSI(n.left());
	RSD(node_aux);
}

template <typename T , class comparar >
void AVL<T,comparar>::RDDI(typename bintree<std::pair<T,int> >::node n){
	typename bintree<std::pair<T,int> >::node node_aux = n;
	RSD(n.right());
	RSI(node_aux);

}
template <typename T , class comparar  >
void AVL<T,comparar>::insert(T valor){
	if(this->find(valor).second == false){ //primero comprobamos si el elemento esta o no esta en el avl , para que no habra elementos repitidos
		typename bintree<std::pair<T,int> >::node nodo = el_avl.root();
		std::pair<T,int> elemento;
		elemento.first=valor;
		elemento.second = 0;      //inicializar la altura del nuevo nodo a 0
		if(el_avl.root().null()){ //si la raiz del arbol es nulo , pues construimos el arbol a partir este valor (el par 'elemento')

			el_avl = bintree<std::pair<T,int>>(elemento);
			tama++;
			nodo = el_avl.root(); //volver a asignar la raiz al nodo nuevo

		}
		else{ //si la raiz no es nulo
			bool encontrado = false;
			while(!encontrado){

//				if((*nodo).first == valor){   //normalemente esta comprobacion , no es necesaria , porque ya hemos comprobado si el elmento esta o no
												// y como ya estamos en esta seccion , pues ya sabemos que este valor no esta en el avl
//					encontrado = true;
//				}
			    if(cmp((*nodo).first,valor ) ){    //si nodo.first no precede a valor en la condicion del functor
					if(nodo.right().null()){
						encontrado = true;
					}
					else{
						nodo = nodo.right();
					}
				}
				else{   // si precede
					if(nodo.left().null()){
						encontrado = true;
					}
					else{
						nodo = nodo.left();
					}
				}
			}
			typename bintree<std::pair<T,int> >::node node_ajuste_altura = nodo; //un nodo auxiliar para reajustar las alturas de los nodos que se afectan
			if( ( cmp((*nodo).first , valor) || !cmp((*nodo).first , valor) ) ){//si nodo.first no precede a valor o si
				if(cmp((*nodo).first,valor)){ //si no precede
					el_avl.insert_right(nodo,elemento);
					this->tama++;
					while( !node_ajuste_altura.null() ){ //en esta bucle asi estamos ajustando la altura
						Ajusta_altura(node_ajuste_altura) ;
						node_ajuste_altura = node_ajuste_altura.parent();
					}

				}
				else{ //si precede
					el_avl.insert_left(nodo,elemento);
					this->tama++;
					while( !node_ajuste_altura.null() ){ // en esta bucle estamos ajustando la altura
						( *node_ajuste_altura ).second = max( h( (node_ajuste_altura).right() )  , h( (node_ajuste_altura).left() ) ) + 1 ;
						node_ajuste_altura = node_ajuste_altura.parent();
					}
				}
			}
		}

		//Rotaciones

			typename bintree<std::pair<T,int> >::node node_aux = nodo ; //un nodo auxiliar que se va a usar para rebalancear

			while(!node_aux.null()){ //si no es nulo
				bool rotacion = false;
				if(es_balanceado(node_aux) == false ){ //comprobar si es balanceado
					std::pair<int,int> resul_aux ;     //un par que se va a utilizar como resultado del metodo que devuelve la altura de las
														// dos ramas "subarboles" de un nodo que es: altura_subarboles_dech_izda_de_un_nodo( node n )

					if( ( h( node_aux.left()) > h( node_aux.right() ) )  ){  //aqui vemos si es necesario realizar una rotacion a la derecha
						resul_aux = altura_subarboles_dech_izda_de_un_nodo(node_aux.left());
						if(resul_aux.first > resul_aux.second){ //si es una rotacion doble a la derecha
							RDID(node_aux);
						}
						else{ //si es una rotacion simple a la derecha
							RSD(node_aux);
						}
						node_aux = node_aux.parent();
						rotacion = true;
					}
					//caso RSI
					else if( ( h( node_aux.left()) < h( node_aux.right() ) ) ) { //comprobar si es una rotacion a la izquierda
						resul_aux = altura_subarboles_dech_izda_de_un_nodo(node_aux.right());
						if(resul_aux.first < resul_aux.second){ //si es una rotacion doble a la izquierda
							RDDI(node_aux);
						}
						else{ //si es una rotacion simple a la izquierda
							RSI(node_aux);
						}
						node_aux = node_aux.parent();
						rotacion = true;
					}
				}
				if(!rotacion)
					node_aux = node_aux.parent();
			}
	}

}
template <typename T , class comparar >
unsigned int AVL<T,comparar>::erase(T valor_a_eliminar){

	if( (find(valor_a_eliminar)).second == true ){ //comprobar si el valor esta en el avl
		typename bintree<std::pair<T,int> >::node node_aux_para_rebalancear , padre_nodo;
			bintree<std::pair<T,int>> dest;
			typename bintree<std::pair<T,int>>::node nodo = el_avl.root();

			bool encontrado = false;

			while(!encontrado && !nodo.null()){ // mientras no se ha encontrado y no es nulo
				if( (*nodo).first == valor_a_eliminar ){ // si la etiqueta del nodo es igual al valor "buscado a eliminar "
					encontrado = true;
				}
				else if( cmp( (*nodo).first,valor_a_eliminar ) ){ //si la etiqueta del nodo precede a valor en el orden del functor
					nodo = nodo.right();
				}
				else{ // si no precede
					nodo = nodo.left();
				}
			}//while
			padre_nodo = nodo.parent();

//			if( nodo.null() ){ //esta seccion de comparacion no es necesaria porque ya sabemos que el elemento esta en el avl , "segun el FIND"
//				return 0;
//			}
		    if( ( nodo.left().null() ) && ( nodo.right().null() ) ){ //  si no tiene ningun hijo

				if(nodo.parent().null()){ //raiz es hoja
					el_avl.clear();
				}
				else if( cmp( (*nodo.parent()).first , valor_a_eliminar ) ){ //si el padre de nodo precede a valor segun el functor
																			//esto significa que el nodo eliminado esta a la derecha de su padre

					el_avl.prune_right(nodo.parent(),dest); //quitamos y guardamos la rama derecha del padre del nodo que se va eliminar
					dest.clear();                          //borramos esta rama
					Ajusta_altura(padre_nodo);             //Ajustamos la altura del padre porque quizas se cambiara en algunos casos
					node_aux_para_rebalancear = padre_nodo; //esta variable se usara en proceso de rebalancear

				}
				else{ //si el padre del nodo que se va a eliminar no precede a valor
					el_avl.prune_left(nodo.parent(),dest); // pues quitamos y guardamos la rama izquierda del padre
					dest.clear(); //borramos esta rama
					Ajusta_altura(padre_nodo); //ajustamos la altura del padre , QUIZAS SE CAMBIARA EN ALGUNOS CASOS
					node_aux_para_rebalancear = padre_nodo; ////esta variable se usara en proceso de rebalancear


				}
			}//else if nº1

			else if( nodo.left().null() || nodo.right().null() ){ //tiene un solo hijo
				if( !nodo.parent().null() ){                   //si el padre del nodo que se va a borrar no es nulo
					node_aux_para_rebalancear = nodo.parent(); //pues asignamos el padre a una variable para el rebalanceo

				}
				if( nodo.left().null() ){ //tiene hijo derecho
					el_avl.prune_right(nodo,dest); //guardamos la rama derecha del nodo borrado
					if( nodo.parent().null() ){ // si el padre es nulo , pues el nodo borrado es la raiz
						el_avl.assign_subtree(dest , dest.root()); //asignamos la rama derecha guardada anteriormente al avl nuestro
					}
					else if( cmp( ( *nodo.parent() ).first , valor_a_eliminar ) ){ //si el padre no es nulo y el valor del padre precede a
																					// a "valor a eliminar "
						el_avl.insert_right(nodo.parent() , dest); //insertamos a la derecha del padre la rama guardada

					}
					else{ // si el padre no es nulo y no precede a valor segun el orden del functor
						el_avl.insert_left(nodo.parent(),dest);  //pues insertamos a la izquierda del padre la rama guardada
					}
				}
				else{ //tiene hijo izquierdo
					el_avl.prune_left(nodo,dest); //guardamos la rama izquierda del nodo que se va a borrar
					if( nodo.parent().null() ){ //si el padre no es nulo
						el_avl.assign_subtree(dest , dest.root()); //asignamos esta rama al avl
					}
					else if( cmp( ( *nodo.parent() ).first , valor_a_eliminar) ){
						el_avl.insert_right(nodo.parent() , dest);
					}
					else{
						el_avl.insert_left(nodo.parent(),dest);
					}

				}
			}
			else{ // si tiene 2 hijos
				bintree<std::pair<T,int>> dest_right , dest_left , subarbo_decho_de_hijo_izq_de_n , subarbo_izq_de_hijo_decho_de_hijo_izq_de_n;
				bool hijo_derecho_no_es_nulo = false;

				el_avl.prune_right(nodo , dest_right); //guardamos la rama derecha del nodo que se va a borrar
				el_avl.prune_left(nodo , dest_left); //guardamos la rama izquierda del nodo que se va a borrar

				if( !dest_left.root().right().null() ){ // si el hijo derecha de la raiz de la rama izquierda no es nulo
					hijo_derecho_no_es_nulo = true;
					//quitar y guardar la rama derecha de la raiz de dest_left "la rama izquierda del nodo borrado"
					dest_left.prune_right(dest_left.root() , subarbo_decho_de_hijo_izq_de_n);

					//quitar y guardar la rama izquierda de la rama derecha de la raiz de dest_left
					subarbo_decho_de_hijo_izq_de_n.prune_left(subarbo_decho_de_hijo_izq_de_n.root(),subarbo_izq_de_hijo_decho_de_hijo_izq_de_n);

					//insertar a la derecha de la raiz de dest_left, la rama izquierda de la rama derecha "ANTERIORMENTE" de la raiz de dest_left
					dest_left.insert_right(dest_left.root(),subarbo_izq_de_hijo_decho_de_hijo_izq_de_n);

					//insertar la rama derecha del nodo borrada "ANTERIORMENTE" :dest_right
					//a la derecha de la raiz de la rama derecha de la raiz de dest_left "ANTERIORMENTE"
					subarbo_decho_de_hijo_izq_de_n.insert_right(subarbo_decho_de_hijo_izq_de_n.root(),dest_right);

					//si el hijo derecho "nuevo" de la raiz de dest_left, no es nulo , pues ajustamos su altura porque en algunos casos se cambiara
					if(!dest_left.root().right().null())
						Ajusta_altura(dest_left.root().right());

					//insertar dest_left a la izquierda de la raiz de la rama derecha de dest_left "ANTERIORMENTE"
					subarbo_decho_de_hijo_izq_de_n.insert_left(subarbo_decho_de_hijo_izq_de_n.root(),dest_left);
				}
				else{ //si el hijo derecha de la raiz de la rama izquierda ES nulo     //este bucle la vamos a llamar "else**"

					//pues insertamos la rama derecha del nodo borrado a la derecha de la rama izquierda del nodo borrado
					dest_left.insert_right(dest_left.root(),dest_right);

				}

				//AHORA AQUI TRABAJAREMOS CON EL PADRE DEL NODO BORRADO
				if(nodo.parent().null()){ //si el padre del nodo borrado es nulo  "el nodo borrado es la raiz"

					if(hijo_derecho_no_es_nulo){ // si el hijo derecha de la raiz de la rama izquierda no es nulo "no hemos trbajado con "else**"

						//pues asignamos el resultado del trabajo lo que se hizo arriba "subarbo_decho_de_hijo_izq_de_n" al avl nuestro
						el_avl.assign_subtree(subarbo_decho_de_hijo_izq_de_n , subarbo_decho_de_hijo_izq_de_n.root());
					}
					else{ // he trbajado con "else**"

						//asignamos dest_left al avl nuestro
						el_avl.assign_subtree(dest_left , dest_left.root());
					}

					//AJUSTAMOS LA ALTURA DE LA RAIZ DEL AVL
					Ajusta_altura(el_avl.root());

					//ASIGNAMOS LA RAIZ DEL AVL A ESTA VARIABLE AUXILIAR PORQUE SE VA A UTILIZAR EN EL PROCESO DE REBALANCEO
					node_aux_para_rebalancear = el_avl.root();

				}
				else{ //si el nodo borrado no es la raiz

					if(hijo_derecho_no_es_nulo){ //// si el hijo derecha de la raiz de la rama izquierda no es nulo "no hemos trbajado con "else**"

						//pues asignamos la raiz del arbol resultante arriba "subarbo_izq_de_hijo_decho_de_hijo_izq_de_n" a una variable auxiliar
						//para el proceso de REBALANCEO
						node_aux_para_rebalancear = subarbo_izq_de_hijo_decho_de_hijo_izq_de_n.root();

						//si el nodo borrado era el hijo izquierdo de su padre
						if(nodo == nodo.parent().left()){
							//pues insertamos a la izquierda del padre del nodo borrado el arbol resultante
							el_avl.insert_left(nodo.parent() , subarbo_decho_de_hijo_izq_de_n);
						}
						else{ //si el nodo borrado era el hijo derecho de su padre

							//pues insertamos el arbo resultante a la derecha del padre del nodo borrado
							el_avl.insert_right(nodo.parent() , subarbo_decho_de_hijo_izq_de_n );
						}
					}
					else{ //si hemos trabajado con "else**" :: si el hijo derecha de la raiz de la rama izquierda ES nulo

						//pues guardamos en una variable auxiliar la raiz del arbol resultante "dest_left" para rebalancear
						node_aux_para_rebalancear = dest_left.root();


						if(nodo == nodo.parent().left()){ //el mismo procedimiento de arriba
							el_avl.insert_left(nodo.parent() , dest_left );
						}
						else{
							el_avl.insert_right(nodo.parent() , dest_left );
						}
					}
				}
			}
			tama--; //decrementa tama en una unidad
		//	Rotaciones      :: AQUI SE USA EL MISMO PROCEDIMIENTO QUE SE USABA EN INSERT
				typename bintree<std::pair<T,int> >::node node_aux = node_aux_para_rebalancear ;
				while(!node_aux.null()){
					Ajusta_altura(node_aux_para_rebalancear);
					bool rotacion = false;
					if(es_balanceado(node_aux) == false ){
						std::pair<int,int> resul_aux ;

						if( ( h( node_aux.left()) > h( node_aux.right() ) )  ){
							resul_aux = altura_subarboles_dech_izda_de_un_nodo(node_aux.left());
							if(resul_aux.first > resul_aux.second){
								RDID(node_aux);
							}
							else{
								RSD(node_aux);
							}
							node_aux = node_aux.parent();
							rotacion = true;
						}
						//caso RSI
						else if( ( h( node_aux.left()) < h( node_aux.right() ) ) ) {
							resul_aux = altura_subarboles_dech_izda_de_un_nodo(node_aux.right());
							if(resul_aux.first < resul_aux.second){
								RDDI(node_aux);
							}
							else{
								RSI(node_aux);
							}
							node_aux = node_aux.parent();
							rotacion = true;
						}
					}
					if(!rotacion)
						node_aux = node_aux.parent();
				}
				return 1;
			}
			else{
				return 0;
			}


}
template <typename T , class comparar  >
typename AVL<T,comparar>::iterator AVL<T,comparar>::lower_bound (const T val) {
	typename AVL<T,comparar>::iterator salida ;
	typename bintree<std::pair<T,int> >::node n = el_avl.root();
	bool encontrado = false;

	while(!encontrado){ //mientras no se ha encontrado el valor buscado
		if( !cmp( (*n).first,val ) && !cmp( val ,(*n).first ) ){ //si el valor del nodo actual es ihual al valor buscado
			encontrado = true;
		}
		else if( cmp( (*n).first,val ) ){ //si el valor del nodo actual precede a val segun el orden del functor
			if(!n.right().null()) //si el hijo derecha del nodo actual no es nulo
				n = n.right();
			else{ //si el hijo derecha del nodo actual ES nulo

				if(n == n.parent().left()){ //si el nodo actual es el hijo izuqierdo de su padre
					n = n.parent();
					encontrado = true;
				}
				else{ //si el nodo actual es el hijo derecho de su padre

					//si el padre del nodo actual es el hijo derecho de su padre
					if( n.parent() == n.parent().parent().right() ){

						//pues ASI SABEMOS QUE EL ELEMENTO NO ESTA Y NO HAY UNO MAYOR QUE EL ; PUES SE ASIGNA A UN NUDO NULO
						n = el_avl.root().parent();
						encontrado = true;


						/*
						 * ESTE CASO SE PUEDE REPRESENTA COMO SIGUIENTE
						 *
						 *                  n.parent().parent()
						 *                  				   \
						 *                  				   n.parent()
						 *                  				   			\
						 *                  				   			nodo actual " su valor es menor que el elemento buscado "
						 *                  				   						\
						 *                  				   						null
						 *
						 */
					}
					else if(n.parent() == n.parent().parent().left() ){ //si el padre del nodo actual es el hijo izquierdo de su padre
						//PUES ASI SABEMOS QUE EL NODO BUSCADO ES EL PADRE DEL PADRE DEL NODO ACTUAL
						n = n.parent().parent();
						encontrado = true;

						/*
						 * ESTE CASO SE PUEDE REPRESENTAR DE LA SIGUIENTE FORMA
						 * 					 n.parent().parnet()
						 * 				    /
						 * 		  n.parent()
						 * 				    \
						 * 					 nodo_actual
						 * 								\
						 * 								null
						 *
						 */

					}

				}
			}
		}
		else{ // si el valor del nodo actual no precede a val segun el orden del functor
			if(!n.left().null())
				n = n.left();
			else{
				encontrado = true;

			}
		}
	}
	if(n == el_avl.root().parent())
		salida = this->end();

	salida.nodo_it = n;
	return salida;

}

//UPPER_BOUND CASI TIENE LA MISMA IMPLEMENTACION QUE LOWER_BOUND PERO SE DIFERENCIA EN UN PUNTO , voy a explicara en el codigo
template <typename T , class comparar  >
typename AVL<T,comparar>::iterator AVL<T,comparar>::upper_bound (const T val) {
	typename AVL<T,comparar>::iterator salida ;
	typename bintree<std::pair<T,int> >::node n = el_avl.root();
	bool encontrado = false;

	while(!encontrado){
		if( !cmp( (*n).first,val ) && !cmp( val ,(*n).first ) ){ //AQUI ES LA DIFERENCIA , SI EL VALOR DEL NODO ACUAL ES IGUAL A VAL , PUES
																// VAMOS A LA DERECHA DEL NODO ACTUAL ; SI NO ES NULO
			if( !n.right().null() ){
				n = n.right();
			}
			else{  //si el hijo derecho del nodo actual ES nulo
				if(n == n.parent().right()){ //si el nodo actual es el hijo derecho de su padre

					//PUES ASI SABEMOS QUE NO HAY UN NODO CON UN VALOR MAYOR ESTRICTO QUE EL VALOR BUSCADO
					n = el_avl.root().parent(); //devolvemos null
				}
				else{ //si el nodo actual es el hijo derecho de su padre

					//PUES ASI SABEMOS QUE EL PRIMER VALOR MAYOR QUE EL VALOR BUSCADO ES EL PADRE DEL NODO ACTUAL
					n = n.parent();
				}
				encontrado = true;
			}
		}
		else if( cmp( (*n).first,val ) ){
			if(!n.right().null())
				n = n.right();
			else{
				//n = end();
				if(n == n.parent().left()){
					n = n.parent();
					encontrado = true;
				}
				else{
					if( n.parent() == n.parent().parent().right() ){
						n = el_avl.root().parent();
						encontrado = true;
					}
					else if(n.parent() == n.parent().parent().left() ){

						n = n.parent().parent();
						encontrado = true;
					}

				}
			}
		}
		else{
			if(!n.left().null())
				n = n.left();
			else{
				encontrado = true;

			}
		}
	}
	if(n == el_avl.root().parent())
		salida = this->end();

	salida.nodo_it = n;
	return salida;

}

/*SEGUN LO QUE ENTENDI EN LA CLASE DE PRACTICA DE LA EXPLICACION DE USTED ; HE IMPLEMENTADO ESTE METODO DE LA SEGUIENTE FORMA
 *SI ESTA MAL ESTO NO QUIERE DECIR QUE USTED HA EXPLICADO MAL ; SINO YO ENTENDI MAL , PERO CREO QUE ESTA BIEN , PORQUE FUNCIONA BIEN
 *
 *SWAP DE BINTREE :
 *			template <typename T>
			inline
			void bintree<T>::swap(bintree<T> & tree){
				typename bintree<T>::node auxiliar;

				auxiliar = tree.laraiz;
				tree.laraiz = this->laraiz;
				this->laraiz = auxiliar;
			}
 *
*/
template <typename T , class comparar  >
void AVL<T, comparar>::swap(AVL<T, comparar> & avl_swap){ //DESPUES DE IMPLEMENTAR EL SWAP EN AVL
	int tama_auxiliar;

	tama_auxiliar = avl_swap.tama;
	avl_swap.tama = this->tama;
	this->tama = tama_auxiliar;

	this->el_avl.swap(avl_swap.el_avl);
}

template <typename T , class comparar  >
bintree<std::pair<T,int>> AVL<T,comparar>::  el_avl_return(){
	return el_avl;
}

template <typename T , class comparar  >
bool AVL<T,comparar>::empty() const{
	return (this->tama == 0);
}
template <typename T , class comparar  >
unsigned int AVL<T,comparar>::size() const{
	return tama;
}
template <typename T , class comparar  >
void  AVL<T,comparar>::clear(){
	el_avl.clear();
	tama = 0;
}
template <typename T , class comparar  >
AVL<T,comparar> & AVL<T,comparar>::operator= (const AVL<T,comparar> & x){
	this->el_avl = x.el_avl;
	this->tama = x.tama;
}











