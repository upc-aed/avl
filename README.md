# Alumno: ____   _______

# AVL Tree

- Modificar los algoritmos de inserción y eliminacion para mantener actualizado la altura de cada nodo en el atributo height. 
- Agregar las funciones de rotación para mantener autobalanceado el árbol binario de búsqueda.
- De este modo mantenemos una complejidad log(n) en la inserción y la eliminación.

```cpp
struct NodeBT {
    T data;
    int height; //altura del nodo
    NodeBT* left; 
    NodeBT* right; 
};
```


