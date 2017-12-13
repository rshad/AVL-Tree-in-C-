#ifndef __AVL_H__
#define __AVL_H__


#include "bintree.h"
#include <functional>   // std::less
#include <algorithm>
#include <iostream>

template <typename T , class comparar = std::less<T> >
class AVL{
public:
	AVL();
	class iterator;
	class const_iterator ;
	class reverse_iterator;
	class const_reverse_iterator;

/*
 * @brief insertar un elemento
 * @param valor , a insertar
 */
	void insert(T valor);

/*
 * @brief buscar un elemento
 * @param vaolr , a buscar
 * @return un pair<iterator,bool>
 */
	std::pair<iterator,bool> find(T valor);



	/*
	 * @brief devuelve el primer del avl segun el orden del functor
	 * @return un iterator que apunta al nodo buscado
	 */
	iterator begin();

	/*
	 * @brief devuelve el end del AVL
	 */
	iterator end();

	/*
	 * @brief devuelve el ultimo valor del AVL segun el oreden del functor
	 * @return un reveres iterator
	 */
	reverse_iterator rbegin();

	/*@brief devuelve el end del AVL
	 *
	 */
	reverse_iterator rend();

	/*
	 * @brief devuelve el primer elemento segun el orden del functor
	 * @return const_iterator
	 */
	const_iterator cbegin();

	/*
	 * @brief devuelve el end del AVL
	 */
	const_iterator cend();

	/*
	 * @brief devuelve el ultimo valor del AVL segun el oreden del functor
	 * @return un const_reveres_iterator
	 */
	const_reverse_iterator rcbegin();

	/*
	 * @brief devuelve el end del AVL
	 */
	const_reverse_iterator rcend();

	/*
	 * @brief elimina un elemento , si esta en el avl
	 * @return 1 si se ha eliminado , 0 en otro caso
	 */
	unsigned int erase(T valor_a_eliminar);

	/*
	 * @brief devuelve al primer elemento igual o mayor a val
	 * @param valor a buscar su lower_bound
	 * @return un iterator
	 */
	iterator lower_bound (const T val);

	/*
	 * @brief devuelve al primer elemento mayor estricto a val
	 * @param valor a buscar su upper_bound
	 * @return un iterator
	 */
	iterator upper_bound (const T val);

	/*
	 * @brief , este es un metodo que lo utilizo para pintar el arbol "NORMALMENTE NO SE PUEDE CONSTRUIRLA PORQUE ROPME LA PRIVACIDAD DEL AVL "
	 * @return un bintree
	 */

	bintree<std::pair<T,int>> el_avl_return() ;

	/*
	 * @brief intercambiar el contenid de 2 avl's
	 * @param avl_swap el avl que se va intercambiar contenido con this
	 */
	void swap(AVL<T, comparar> & avl_swap);

	/*
	 * @brief no informa si el avl esta vacio
	 * @return un bool
	 */
	bool empty() const;

	/*
	 * @brief devuelve el tamaño del avl
	 * @return unsigned int
	 */
	unsigned int size() const;

	/*
	 *@brief limpia el avl "pone el tamano a 0"
	 */
	void clear();

	class reverse_iterator {
	  public:
	    /**
	       @brief Constructor primitivo por defecto.
	    */
	    reverse_iterator();

	    /**
	       @brief Constructor de copia.
	    */
	    reverse_iterator(const reverse_iterator & ite);

	    /**
	       @brief Operador de incremento.

	       @pre El BST asociado NO ha sido modificado despu�s
	       de la creaci�n del iterador receptor.
	       @pre El iterador receptor NO est� al final del recorrido:
	       (receptor) != end()

	       @return  Posici�n actual en el recorrido creciente del BST
	                asociado.

		Modifica el (iterador) receptor haci�ndolo apuntar al
		siguiente elemento en el recorrido creciente del
		BST asociado.
	    */
	    reverse_iterator & operator++();

	    /**
	       @brief Obtener el elemento al que apunta el iterator.

	       @pre El BST asociado NO ha sido modificado despu�s
	       de la creaci�n del iterador receptor.
	       @pre El iterador receptor NO est� al final del recorrido:
	       (receptor) != end()

	       @return
	       El par <Key,T> correspondiente al dato de la posici�n actual
	       del recorrido.
	    */
	    std::pair<T,int> operator*() const;


	    /**
	       @brief Comparaci�n de igualdad.

	       @param i: Segundo iterador en la comparaci�n.
	       @return true, si el receptor e i tienen el mismo valor.
	       false, en caso contrario.
	    */
	    bool operator==(const reverse_iterator &i) const;

	    /**
	       Comparacion de igualdad.

	       @param i: Segundo iterador en la comparaci�n.
	       @return false, si el receptor e i tienen el mismo valor.
	       true, en caso contrario.
	    */
	    bool operator!=(const reverse_iterator &i) const;

	    reverse_iterator & operator=(const reverse_iterator &i);

	    reverse_iterator & operator--();

	  private:

	    friend class AVL;

	    typename bintree<std::pair<T,int> >::node nodo_it;
	  };

	class const_reverse_iterator {
	public:
	    /** @brief constructor por defecto
	    */
		const_reverse_iterator();
	   	/** @brief constructor de copia
	   	@param[in] it iterator a copiar
	   	*/
		const_reverse_iterator(const const_reverse_iterator & it);

      /** @brief operador * que devuelve el contendio de donde apunta el iterator
       */
	  const std::pair<T,int>  & operator*() const;

      /** @brief operador de incrementar un iterator de forma ++it
       incrementa el it en 1
      */
	  const_reverse_iterator & operator++();

      /** @brief operador de decrementar un iterator de forma --it.
       deccrementa el it en 1
      */
	  const_reverse_iterator & operator--();
      /** @brief operador de asignacion
       @param it a asignar
      */
	  const_reverse_iterator & operator=(const_reverse_iterator it);
      /** @brief operador de comparacion si dos iteradores son iguales
       @param it es un operator que se va a comparar con this.
      */
	  bool operator==(const const_reverse_iterator & it);
      /** @brief operador de comparacion si dos iteradores no son iguales
       @param it es un operator que se va a comparar con this.
      */
	  bool operator!=(const const_reverse_iterator & it);
	private:
	    friend class AVL;
	    typename bintree<std::pair<T,int> >::const_node nodo_it;

	};



	class iterator {
	  public:
	    /**
	       @brief Constructor primitivo por defecto.
	    */
	    iterator();

	    /**
	       @brief Constructor de copia.
	    */
	    iterator(const iterator & ite);

	    /**
	       @brief Operador de incremento.

	       @pre El BST asociado NO ha sido modificado despu�s
	       de la creaci�n del iterador receptor.
	       @pre El iterador receptor NO est� al final del recorrido:
	       (receptor) != end()

	       @return  Posici�n actual en el recorrido creciente del BST
	                asociado.

		Modifica el (iterador) receptor haci�ndolo apuntar al
		siguiente elemento en el recorrido creciente del
		BST asociado.
	    */
	    iterator & operator++();

	    /**
	       @brief Obtener el elemento al que apunta el iterator.

	       @pre El BST asociado NO ha sido modificado despu�s
	       de la creaci�n del iterador receptor.
	       @pre El iterador receptor NO est� al final del recorrido:
	       (receptor) != end()

	       @return
	       El par <Key,T> correspondiente al dato de la posici�n actual
	       del recorrido.
	    */
	    std::pair<T,int> operator*() const;


	    /**
	       @brief Comparaci�n de igualdad.

	       @param i: Segundo iterador en la comparaci�n.
	       @return true, si el receptor e i tienen el mismo valor.
	       false, en caso contrario.
	    */
	    bool operator==(const iterator &i) const;

	    /**
	       Comparacion de igualdad.

	       @param i: Segundo iterador en la comparaci�n.
	       @return false, si el receptor e i tienen el mismo valor.
	       true, en caso contrario.
	    */
	    bool operator!=(const iterator &i) const;

	    iterator & operator=(const iterator &i);

	    iterator & operator--();

	  private:

	    friend class AVL;
	    typename bintree<std::pair<T,int> >::node nodo_it;
	};

	class const_iterator {
	public:
	    /** @brief constructor por defecto
	    */
	  const_iterator();
	   	/** @brief constructor de copia
	   	@param[in] it iterator a copiar
	   	*/
	  const_iterator(const const_iterator & it);
          /** @brief Convierte iterator en const_iterator
          */
	  const_iterator(const iterator & it);
      /** @brief operador * que devuelve el contendio de donde apunta el iterator
       */
	  const std::pair<T,int>  & operator*() const;

      /** @brief operador de incrementar un iterator de forma ++it
       incrementa el it en 1
      */
	  const_iterator & operator++();

      /** @brief operador de decrementar un iterator de forma --it.
       deccrementa el it en 1
      */
      const_iterator & operator--();
      /** @brief operador de asignacion
       @param it a asignar
      */
      const_iterator & operator=(const_iterator it);
      /** @brief operador de comparacion si dos iteradores son iguales
       @param it es un operator que se va a comparar con this.
      */
	  bool operator==(const const_iterator & it);
      /** @brief operador de comparacion si dos iteradores no son iguales
       @param it es un operator que se va a comparar con this.
      */
	  bool operator!=(const const_iterator & it);
	private:
	    friend class AVL;
	    typename bintree<std::pair<T,int> >::const_node nodo_it;

	};

private:
  // Metodos privados

	/*
	 * @brief rotacion simple a derecha
	 * @param n el nodo de desequilibrio
	 *
	 */
  void RSD(typename bintree<std::pair<T,int> >::node n);

	/*
	 * @brief rotacion simple a izuierda
	 * @param n el nodo de desequilibrio
	 *
	 */
  void RSI(typename bintree<std::pair<T,int> >::node n);

	/*
	 * @brief rotacion doble izquierda derecha
	 * @param n el nodo de desequilibrio
	 *
	 */
  void RDID(typename bintree<std::pair<T,int> >::node n);

	/*
	 * @brief rotacion doble derecha izquierda
	 * @param n el nodo de desequilibrio
	 *
	 */
  void RDDI(typename bintree<std::pair<T,int> >::node n);

  /*
   * @brief Ajusta la altura de un nodo n
   * @param n el nodo para ajusta su altura
   */
  void Ajusta_altura(typename bintree<std::pair<T,int> >::node n);

  /*
   * @brief devuelve la altura de las subarboles derecha , izquierda de un nodo , sucesivamente
   * @param n el nodo con el que se va a trabajar
   * @return un par de int,int
   */
  std::pair<int,int> altura_subarboles_dech_izda_de_un_nodo(typename bintree<std::pair<T,int> >::node n);
	/*
	 * @brief detectar si un nodo esta balanceado o no
	 * @param n , el nodo que para detectar
	 * @return un bool
	 */
	bool es_balanceado(typename bintree<std::pair<T,int> >::node  n);

	AVL<T,comparar> & operator= (const AVL<T,comparar> & x);

/*
 * @brief devuelve la altura de un nodo
 * @param n el nodo para sacar su altura
 * @return un entero
 */
  int h(typename bintree<std::pair<T,int> >::node  n);

  /*
   * @brief devuelve la altura de un nodo
   * @param n un nodo constante para sacar su altura
   * @return un entero
   */
  int h(typename bintree<std::pair<T,int> >::const_node  n);
 // Representacion
  bintree <std::pair<T,int> > el_avl;
  unsigned int tama;
  comparar cmp;

};


#endif
