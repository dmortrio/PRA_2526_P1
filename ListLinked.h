#include <ostream>
#include "List.h"
#include "Node.h"
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;
        // Número de elementos
        int n;

    public:
        // Constructor
        ListLinked() {
            first = nullptr;
            n = 0;
        }

        // Destructor
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }

        // Sobrecarga de []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }
            Node<T>* aux = first;
            // Avance al nodo
            for (int i = 0; i < pos; ++i) {
                aux = aux->next;
            }
            return aux->data;
        }

        // Sobrecarga de <<
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            out << "List => [";
            Node<T>* aux = list.first;
            while (aux != nullptr) {
                out << aux->data;
                if (aux->next != nullptr) {
                    out << ", ";
                }
                aux = aux->next;
            }
            out << "]";
            return out;
        }

       

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición de inserción inválida");
            }

            // inserta al inicio
            if (pos == 0) {
                //actu del nuevo nodo
                first = new Node<T>(e, first);
            } else {
                // Caso general(inserta al medio o en el final)
                Node<T>* prev = first;
                // Busqueda del anterior nodo
                for (int i = 0; i < pos - 1; ++i) {
                    prev = prev->next;
                }
                //nuevo nodo
                prev->next = new Node<T>(e, prev->next);
            }
            n++;
        }

        void append(T e) override {
            insert(n, e); // Insertar al final
        }

        void prepend(T e) override {
            insert(0, e); // Insertar al inicio
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición de eliminación inválida");
            }

            Node<T>* toDelete;
            T data;

            // elimina primer nodo
            if (pos == 0) {
                toDelete = first;
                first = first->next;
            } else {
             
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; ++i) {
                    prev = prev->next;
                }
                toDelete = prev->next;
                prev->next = toDelete->next; 
            }

            data = toDelete->data;
            delete toDelete;
            n--;
            
            return data;
        }

        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida");
            }
            Node<T>* aux = first;
            for (int i = 0; i < pos; ++i) {
                aux = aux->next;
            }
            return aux->data;
        }

        int search(T e) override {
            Node<T>* aux = first;
            int i = 0;
            while (aux != nullptr) {
                if (aux->data == e) {
                    return i;
                }
                aux = aux->next;
                i++;
            }
            return -1;
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }
};
