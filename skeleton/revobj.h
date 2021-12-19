#ifndef REVOBJ_H
#define REVOBJ_H

#include "object3d.h"
#include "math.h"

class _revOBJ:public _object3D
{
private:

    //Ejes para Rotar
    enum AxisRotation{axis_x,axis_y,axis_z};

    /**
     * @brief axis_selection
     *
     * Variable que indica en que eje se va a rotar el objeto
     */
    AxisRotation axis_selection = axis_y;

    /**
     * @brief pLine
     * Polilinea (perfil) que define la figura.
     */
    vector<_vertex3f> pLine;

    /**
     * @brief n
     * Numero de Rotaciones que hacemos
     */
    int n;

    /**
     * @brief Construct
     * Funcion Que construye la figura.
     */
    void Construct();

    bool checkN(const int n);

public:

    /**
     * @brief Construct a new revOBJ object
     * 
     */
    _revOBJ(){};

    /**
     * @brief _revOBJ
     * @param _n
     * Constructor con solo N tiene un punto de perfil por defecto
     */
    _revOBJ(int _n);

    /**
     * @brief _revOBJ
     * @param _pLine
     * @param _n
     * Constructor con la polilinea (pLine) y el numero de rotaciones (n)
     */
    _revOBJ(vector<_vertex3f> _pLine,int _n);

    ~_revOBJ();

    /**
     * @brief getN
     * @return Numero de Rotaciones
     */
    int getN(){
        return n;
    }

    /**
     * @brief ChangeN
     * @param _n
     * Cambia el valor de N y vuelve a construir la figura
     */
    void ChangeN(int _n);

    /**
     * @brief ChangeProfile
     * @param _pLin
     * Cambia el Valor de la polilinea (pLine) y vuelve a construir la figura
     */
    void ChangeProfile(vector<_vertex3f> _pLin);

    /**
     * @brief ChangeREV
     * @param _pLine
     * @param _n
     * Cambia el valor de N y Cambia el Valor de la polilinea (pLine) despues vuelve a construir la figura
     */
    void ChangeREV(vector<_vertex3f> _pLine,int _n);

    /**
     * @brief getProfile
     * @return Polilinea (pLine)
     * Cambia el eje de rotacion
     */
    void SelectRotationAxis(AxisRotation _axis);

    /**
     * @brief getProfile
     * @return Polilinea (pLine)
     * Cambia todos los parametros del objeto y vuelve a construir la figura
     */
    void ChangeOBJ(vector<_vertex3f> _pLine, int _n,AxisRotation _axis);

};

#endif // REVOBJ_H