#include "bintree.h"
#include "avl.hxx"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
#define placeholder (1<<31)
// create a pretty vertical tree
void postorder(bintree< pair<int,int> >::node p);
void getLine(const bintree< pair<int,int> >::node root, int depth, vector<int>& vals);
void printRow(const bintree< pair<int,int> >::node p, const int height, int depth);

void postorder(typename bintree< pair<int,int> >::node p)
{
	int height = ((*(p)).second) * 2;
	for (int i = 0 ; i < height; i ++) {
        printRow(p, height, i);
    }
}
void getLine(const bintree< pair<int,int> >::node root, int depth, vector<int>& vals)
{
        if (depth <= 0 && !(root).null() ){
                vals.push_back((*(root)).first);
                return;
        }
        if (!(root).left().null())
                getLine(((root).left()), depth-1, vals);
        else if (depth-1 <= 0)
                vals.push_back(placeholder);
        if (!(root).right().null())
                getLine((root).right(), depth-1, vals);
        else if (depth-1 <= 0)
                vals.push_back(placeholder);
}


void printRow(const bintree< pair<int,int> >::node p, const int height, int depth)
{
        vector<int> vec;
        getLine(p, depth, vec);
        cout << setw((height - depth)*2); // scale setw with depth
        bool toggle = true; // start with left
        if (vec.size() > 1) {
                for (int v : vec) {
                        if (v != placeholder) {
                                if (toggle)
                                        cout << "/" << "   ";
                                else
                                        cout << "\\" << "   ";
                        }
                        toggle = !toggle;
                }
                cout << endl;
                cout << setw((height - depth)*2);
        }
        for (int v : vec) {
                if (v != placeholder)
                        cout << v << "   ";
        }
        cout << endl;
}

int main(){


	cout<<" *********************************************** SECCION less<int> ************************************************* "<<endl;


	AVL<int , less<int>> test;
		test.insert(10);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(12);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(11);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(1);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(6);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(17);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(16);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(4);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(8);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(9);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(44);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(45);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;
		test.insert(46);
		postorder((test.el_avl_return().root()));
		cout<<"************************"<<endl;

		cout<<" *********************************************** SECCION DE LOWER_BOUND ************************************************* "<<endl;

			AVL<int,less<int>>::iterator it_low  ;

			it_low = test.lower_bound(0);
			cout<<"lower_bound de 0  es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.lower_bound(1);
			cout<<"lower_bound de 1 es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.lower_bound(19);
			cout<<"lower_bound de 19 es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.lower_bound(20);
			cout<<"lower_bound de 20  es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.lower_bound(21);
			cout<<"lower_bound de 21  es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.lower_bound(5);
			cout<<"lower_bound de  5 es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.lower_bound(16);
			cout<<"lower_bound de 16  es : "<<(*it_low).first<<endl;


			cout<<"***************************************** SECCION DE UPPER_BOUND ******************************************************** "<<endl;

			it_low = test.upper_bound(0);
			cout<<"upper_bound de 0  es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.upper_bound(1);
			cout<<"upper_bound de 1 es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.upper_bound(19);
			cout<<"upper_bound de 19 es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.upper_bound(20);
			cout<<"upper_bound de 20  es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.upper_bound(21);
			cout<<"upper_bound de 21  es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;
			it_low = test.upper_bound(5);
			cout<<"upper_bound de  5 es : "<<(*it_low).first<<endl;
			cout<<"************************"<<endl;

			it_low = test.upper_bound(70);
			if(it_low != test.end())
				cout<<"upper_bound de 70  es : "<<(*it_low).first<<endl;
			else{
				cout<<"upper_bound de 70  es nulo"<<endl;

			}


			cout<<endl<<"************************"<<endl<<" TENEMOS LOS SIGUIENTES ELEMENTOS : "<<endl;

			cout<<" RECORRER EL AVL POR ITERATOR "<<endl;


			AVL<int,less<int>>::iterator it;

			it = test.begin();
			while(it != test.end()){
				cout<<(*it).first<<" ";
				++it;
			}

			cout<<endl<<"**************************"<<endl<<" RECORRER EL AVL POR CONST_ITERATOR "<<endl;


			AVL<int,less<int>>::const_iterator it_const;

			it_const = test.cbegin();
			while(it_const != test.cend()){
				cout<<(*it_const).first<<" ";
				++it_const;
			}

			cout<<endl<<"**************************"<<endl<<" RECORRER EL AVL POR REVERSE_ITERATOR "<<endl;

			AVL<int,less<int>>::reverse_iterator rev_it;

			rev_it = test.rbegin();
			while(rev_it!= test.rend()){
				cout<<(*rev_it).first<<" ";
				++rev_it;
			}
			cout<<endl<<"**************************"<<endl;

			cout<<endl<<"**************************"<<endl<<" RECORRER EL AVL POR CONST_REVERSE_ITERATOR "<<endl;

			AVL<int,less<int>>::const_reverse_iterator const_rev_it;

			const_rev_it = test.rcbegin();
			while(const_rev_it != test.rcend()){
				cout<<(*const_rev_it).first<<" ";
				++const_rev_it;
			}

			test.clear();
			if(test.empty())   //COMPROPACION DE EMPTY()
				cout<<endl<<"**************************"<<endl<<" ****** * * * DESPUES DE UTILIZAR CLEAR, EL AVL ESTA VACIO * * * ********"<<endl<<"*******************"<<endl;

			cout<<"****** * * * * * VOLVER A INSERTAR LOS VALORES EN EL AVL , PARA BORRAR UNO A UNO UTILIZANDO ERASE * * * * ** ************ "<<endl;

			test.insert(10);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(12);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(11);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(1);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(6);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(17);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(16);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(4);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(8);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(9);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(44);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(45);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(46);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;


			cout<<endl<<"**************************"<<endl<<" SECCION ERASE "<<endl;
			cout<<" ANTES DE ELIMINAR NINGUN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;

			cout<<endl;


			test.erase(10);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 10 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;

			test.erase(12);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 12 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;


			test.erase(11);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 11 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;


			test.erase(1);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 1 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;

			test.erase(6);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 6 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;


			test.erase(17);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 17 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			test.erase(44);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 44 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;

			test.erase(46);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 46 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;

			test.erase(45);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 45 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;

			test.erase(16);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 16 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;


			test.erase(4);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 4 TENEMOS "<<endl;
			postorder((test.el_avl_return().root()));

			cout<<endl;

			test.erase(9);
			cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 9 TENEMOS "<<endl;
			cout<<(*test.el_avl_return().root()).first;

			cout<<endl;

			test.erase(8);
			cout<<" DESPUES DE ELIMINAR EL ELEMENTO 8 TENEMOS TAMANO "<<test.size()<<endl;

			cout<<endl;



			cout<<endl<<"*************************"<<endl<<"DESPUES DEL ERASE TENEMOS : "<<endl;

			cout<<endl<<"*************************"<<endl;

			if(test.empty())   //COMPROPACION DE EMPTY()
				cout<<"EL AVL ESTA VACIO"<<endl;


			test.insert(10);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(12);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(11);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(1);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(6);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(17);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(16);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(4);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(8);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(9);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(44);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(45);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;
			test.insert(46);
			postorder((test.el_avl_return().root()));
			cout<<"************************"<<endl;

			cout<<"************* * * * * * * * *  * SECCION DE SWAP * * * * * * * * ********************************"<<endl;

			AVL<int,less<int>> test_2;
			test_2.insert(1);
			test_2.insert(3);
			test_2.insert(7);
			test_2.insert(11);
			test_2.insert(17);
			test_2.insert(33);
			test_2.insert(40);
			test_2.insert(50);
			test_2.insert(1);
			test_2.insert(8);

			cout<<"ESTOS SON LOS VALORES DEL PRIMER AVL"<<endl;

			it = test.begin();
			while(it != test.end()){
				cout<<(*it).first<<" ";
				++it;
			}

			cout<<"************************"<<endl;


			cout<<endl<<"ESTOS SON LOS VALORES DEL SEGUNDO AVL"<<endl;


			AVL<int,less<int>>::iterator it_test_2 = test_2.begin();
			while(it_test_2 != test_2.end()){
				cout<<(*it_test_2).first<<" ";
				++it_test_2;
			}

			cout<<endl<<"************************"<<endl;


			test.swap(test_2);

			cout<<endl<<"ESTOS SON LOS VALORES DEL PRIMER AVL DESPUES DEL SWAP"<<endl;

			it = test.begin();
			while(it != test.end()){
				cout<<(*it).first<<" ";
				++it;
			}

			cout<<endl<<"************************"<<endl;


			cout<<endl<<"ESTOS SON LOS VALORES DEL SEGUNDO AVL DESPUES DEL SWAP"<<endl;

			it_test_2 = test_2.begin();
			while(it_test_2 != test_2.end()){
				cout<<(*it_test_2).first<<" ";
				++it_test_2;
			}

			cout<<endl<<"************************"<<endl;











/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
	cout<<" *********************************************** SECCION greater<int> ************************************************* "<<endl;

			AVL<int , greater<int>> test;
				test.insert(10);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(12);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(11);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(1);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(6);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(17);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(16);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(4);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(8);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(9);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(44);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(45);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;
				test.insert(46);
				postorder((test.el_avl_return().root()));
				cout<<"************************"<<endl;

				cout<<" *********************************************** SECCION DE LOWER_BOUND ************************************************* "<<endl;

					AVL<int,greater<int>>::iterator it_low  ;

					it_low = test.lower_bound(0);
					if(it_low != test.end())
						cout<<"lower_bound de 0  es : "<<(*it_low).first<<endl;
					else
						cout<<"lower_bound de 0  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.lower_bound(1);
					if(it_low != test.end())
						cout<<"lower_bound de 1  es : "<<(*it_low).first<<endl;
					else
						cout<<"lower_bound de 1  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.lower_bound(19);
					if(it_low != test.end())
						cout<<"lower_bound de 19  es : "<<(*it_low).first<<endl;
					else
						cout<<"lower_bound de 19  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.lower_bound(20);
					if(it_low != test.end())
						cout<<"lower_bound de 20  es : "<<(*it_low).first<<endl;
					else
						cout<<"lower_bound de 20  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.lower_bound(21);
					if(it_low != test.end())
						cout<<"lower_bound de 21  es : "<<(*it_low).first<<endl;
					else
						cout<<"lower_bound de 21  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.lower_bound(5);
					if(it_low != test.end())
						cout<<"lower_bound de 5  es : "<<(*it_low).first<<endl;
					else
						cout<<"lower_bound de 5  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.lower_bound(16);
					if(it_low != test.end())
						cout<<"lower_bound de 16  es : "<<(*it_low).first<<endl;
					else
						cout<<"lower_bound de 16  es nulo"<<endl;

					cout<<"***************************************** SECCION DE UPPER_BOUND ******************************************************** "<<endl;

					it_low = test.upper_bound(0);
					if(it_low != test.end())
						cout<<"upper_bound de 0  es : "<<(*it_low).first<<endl;
					else
						cout<<"upper_bound de 0  es nulo"<<endl;

					cout<<"************************"<<endl;
					it_low = test.upper_bound(1);
					if(it_low != test.end())
						cout<<"upper_bound de 1  es : "<<(*it_low).first<<endl;
					else
						cout<<"upper_bound de 1  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.upper_bound(19);
					if(it_low != test.end())
						cout<<"upper_bound de 19  es : "<<(*it_low).first<<endl;
					else
						cout<<"upper_bound de 19  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.upper_bound(20);
					if(it_low != test.end())
						cout<<"upper_bound de 20  es : "<<(*it_low).first<<endl;
					else
						cout<<"upper_bound de 20  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.upper_bound(21);
					if(it_low != test.end())
						cout<<"upper_bound de 21  es : "<<(*it_low).first<<endl;
					else
						cout<<"upper_bound de 21  es nulo"<<endl;
					cout<<"************************"<<endl;
					it_low = test.upper_bound(5);
					if(it_low != test.end())
						cout<<"upper_bound de 5  es : "<<(*it_low).first<<endl;
					else
						cout<<"upper_bound de 5  es nulo"<<endl;
					cout<<"************************"<<endl;

					it_low = test.upper_bound(70);
					if(it_low != test.end())
						cout<<"upper_bound de 70  es : "<<(*it_low).first<<endl;
					else
						cout<<"upper_bound de 70  es nulo"<<endl;




					cout<<endl<<"************************"<<endl<<" TENEMOS LOS SIGUIENTES ELEMENTOS : "<<endl;

					cout<<" RECORRER EL AVL POR ITERATOR "<<endl;


					AVL<int,greater<int>>::iterator it;

					it = test.begin();
					while(it != test.end()){
						cout<<(*it).first<<" ";
						++it;
					}

					cout<<endl<<"**************************"<<endl<<" RECORRER EL AVL POR CONST_ITERATOR "<<endl;


					AVL<int,greater<int>>::const_iterator it_const;

					it_const = test.cbegin();
					while(it_const != test.cend()){
						cout<<(*it_const).first<<" ";
						++it_const;
					}

					cout<<endl<<"**************************"<<endl<<" RECORRER EL AVL POR REVERSE_ITERATOR "<<endl;

					AVL<int,greater<int>>::reverse_iterator rev_it;

					rev_it = test.rbegin();
					while(rev_it!= test.rend()){
						cout<<(*rev_it).first<<" ";
						++rev_it;
					}
					cout<<endl<<"**************************"<<endl;

					cout<<endl<<"**************************"<<endl<<" RECORRER EL AVL POR CONST_REVERSE_ITERATOR "<<endl;

					AVL<int,greater<int>>::const_reverse_iterator const_rev_it;

					const_rev_it = test.rcbegin();
					while(const_rev_it != test.rcend()){
						cout<<(*const_rev_it).first<<" ";
						++const_rev_it;
					}

					cout<<endl<<"**************************"<<endl<<" SECCION ERASE "<<endl;
					cout<<" ANTES DE ELIMINAR NINGUN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;

					cout<<endl;


					test.erase(10);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 10 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;

					test.erase(12);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 12 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;


					test.erase(11);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 11 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;


					test.erase(1);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 1 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;

					test.erase(6);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 6 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;


					test.erase(17);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 17 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					test.erase(44);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 44 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;

					test.erase(46);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 46 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;

					test.erase(45);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 45 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;

					test.erase(16);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 16 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;


					test.erase(4);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 4 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;

					test.erase(9);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 9 TENEMOS "<<endl;
					cout<<(*test.el_avl_return().root()).first;

					cout<<endl;

					test.erase(8);
					cout<<" DESPUES DE ELIMINAR UN ELEMENTO TENEMOS EL TAMANO "<<test.size()<<endl;
					cout<<" DESPUES DE ELIMINAR EL ELEMENTO 8 TENEMOS "<<endl;
					postorder((test.el_avl_return().root()));

					cout<<endl;



					cout<<endl<<"*************************"<<endl<<"DESPUES DEL ERASE TENEMOS : "<<endl;


					it = test.begin();
					while(it != test.end()){
						cout<<(*it).first<<" ";
						++it;
					}

					cout<<endl<<"*************************"<<endl;

					postorder((test.el_avl_return().root()));
*/









	//*************** * * * * * * * * ***** * * * * * SECCION DE AVL<STRING , LESS<STRING> > ******** * * * ** * * * * * * * *













/*
	AVL<string, less<string>> test_string;
		test_string.insert("A");
		test_string.insert("B");
		test_string.insert("C");
		test_string.insert("D");
		test_string.insert("E");
		test_string.insert("F");
		test_string.insert("G");
		test_string.insert("H");
		test_string.insert("I");
		test_string.insert("J");
		test_string.insert("K");
		test_string.insert("L");
		test_string.insert("M");
		test_string.insert("N");
		test_string.insert("Q");

	cout<<"SECCION ITERATOR"<<endl;
	AVL<string, less<string>>::iterator it_string = test_string.begin();
	while(it_string != test_string.end()){
		cout<<(*it_string).first<<" ";
		++it_string;
	}

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	cout<<"SECCION REVERSE ITERATOR"<<endl;
	AVL<string, less<string>>::reverse_iterator it_string_reverse = test_string.rbegin();
	while(it_string_reverse != test_string.rend()){
		cout<<(*it_string_reverse).first<<" ";
		++it_string_reverse;
	}

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	test_string.erase("A");
	it_string = test_string.begin();
	while(it_string != test_string.end()){
		cout<<(*it_string).first<<" ";
		++it_string;
	}

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	test_string.erase("B");
	it_string = test_string.begin();
	while(it_string != test_string.end()){
		cout<<(*it_string).first<<" ";
		++it_string;
	}

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	test_string.erase("C");
	it_string = test_string.begin();
	while(it_string != test_string.end()){
		cout<<(*it_string).first<<" ";
		++it_string;
	}
	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	cout<<endl<<"*************** * * * * * ******* * *** SECCION DE UPPER ITERATOR * * * * * * *****************"<<endl;

	it_string = test_string.upper_bound("L");
	cout<<"UPPER BOUND DE L ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;


	it_string = test_string.upper_bound("F");
	cout<<"UPPER BOUND DE F ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	it_string = test_string.upper_bound("H");
	cout<<"UPPER BOUND DE H  ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	cout<<endl<<"*************** * * * * * ******* * *** SECCION DE LOWER ITERATOR * * * * * * *****************"<<endl;

	it_string = test_string.lower_bound("L");
	cout<<"LOWER BOUND DE L ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;


	it_string = test_string.lower_bound("F");
	cout<<"LOWER BOUND DE F ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	it_string = test_string.lower_bound("H");
	cout<<"LOWER BOUND DE H  ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	it_string = test_string.lower_bound("A");
	cout<<"LOWER BOUND DE A ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;


	cout<<"Esto es el tamno del avl : "<<test_string.size()<<endl;

	test_string.clear();

	cout<<"Esto es el tamno del avl DESPUES DE CLEAR : "<<test_string.size()<<endl;

*/







//*************** * * * * * * * * ***** * * * * * SECCION DE AVL<STRING , GREATER<STRING> > ******** * * * ** * * * * * * * *






/*


	AVL<string, greater<string>> test_string;
		test_string.insert("A");
		test_string.insert("B");
		test_string.insert("C");
		test_string.insert("D");
		test_string.insert("E");
		test_string.insert("F");
		test_string.insert("G");
		test_string.insert("H");
		test_string.insert("I");
		test_string.insert("J");
		test_string.insert("K");
		test_string.insert("L");
		test_string.insert("M");
		test_string.insert("N");
		test_string.insert("Q");

	cout<<"SECCION ITERATOR"<<endl;
	AVL<string, greater<string>>::iterator it_string = test_string.begin();
	while(it_string != test_string.end()){
		cout<<(*it_string).first<<" ";
		++it_string;
	}

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	cout<<"SECCION REVERSE ITERATOR"<<endl;
	AVL<string, greater<string>>::reverse_iterator it_string_reverse = test_string.rbegin();
	while(it_string_reverse != test_string.rend()){
		cout<<(*it_string_reverse).first<<" ";
		++it_string_reverse;
	}

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	test_string.erase("A");
	it_string = test_string.begin();
	while(it_string != test_string.end()){
		cout<<(*it_string).first<<" ";
		++it_string;
	}

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	test_string.erase("B");
	it_string = test_string.begin();
	while(it_string != test_string.end()){
		cout<<(*it_string).first<<" ";
		++it_string;
	}

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	test_string.erase("C");
	it_string = test_string.begin();
	while(it_string != test_string.end()){
		cout<<(*it_string).first<<" ";
		++it_string;
	}
	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	cout<<endl<<"*************** * * * * * ******* * *** SECCION DE UPPER ITERATOR * * * * * * *****************"<<endl;

	it_string = test_string.upper_bound("L");
	cout<<"UPPER BOUND DE L ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;


	it_string = test_string.upper_bound("F");
	cout<<"UPPER BOUND DE F ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	it_string = test_string.upper_bound("H");
	cout<<"UPPER BOUND DE H  ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	cout<<endl<<"*************** * * * * * ******* * *** SECCION DE LOWER ITERATOR * * * * * * *****************"<<endl;

	it_string = test_string.lower_bound("L");
	cout<<"LOWER BOUND DE L ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;


	it_string = test_string.lower_bound("F");
	cout<<"LOWER BOUND DE F ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	it_string = test_string.lower_bound("H");
	cout<<"LOWER BOUND DE H  ES "<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;

	it_string = test_string.lower_bound("A");
	if(it_string == test_string.end())
		cout<<"LOWER BOUND DE A ES  NULL"<<endl;
	else
		cout<<"LOWER BOUND DE A ES  NULL"<<(*it_string).first<<" ";

	cout<<endl<<"*************** * * * * * ******* * *** ************* * * * * *************** * * * * * * *****************"<<endl;


	cout<<"Esto es el tamno del avl : "<<test_string.size()<<endl;

	test_string.clear();

	cout<<"Esto es el tamno del avl DESPUES DE CLEAR : "<<test_string.size()<<endl;


*/




}



