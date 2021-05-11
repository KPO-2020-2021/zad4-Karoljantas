#pragma once
#include "matrix.hh"
#include "vector.hh"
/*!
 * \brief Kalasa opisujaca prostopadloscian
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu prostopadloscianu
 */
class  prism{
   Vector<3> point[SIZE_PRISM];
   public:
    prism(){};
    prism(  Vector<3> pkt0, double wysokosc, double szerokosc, double dlugosc);

const   Vector<3> &operator [] (int index) const;
  Vector<3> &operator [] (int index) ;
 prism operator + (  Vector<3> move);
void move_r(  Vector<3> move);
void rot(Matrix<3> mac);

};
/*!
 * rotacja bryly                                                          |
 *  Argumenty:                                                                |
 *     \param[in] mac - macie obr                                                 |
 *                                                |
 *                                                                    |
 *    \retval  bryla po obr                              |
 */
void prism::rot(Matrix<3> mac)
{
    for(int i=0;i< SIZE_PRISM;i++)
    {
        point[i]=mac*point[i];
    }
   
}
/*!
 * Konstruktor parametryczny budujacy prostopadloscian przez obliczenie wierzcholkow na podstawie
 * podanych danych punbktu pierwszego oraz długiosci i szerokosci
 * \param[in] pkt0 - wektor poczatkowy okreslajacy lewy dolny rog prostopadloscianu
 * \param[in] wysokosc - parametr przyjmujacy wysokosci prostopadloscianu
 * \param[in] szerokosc - parametr przyjmujacy szerokosc prostopadloscianu
 \param[in] dlugosc - parametr przyjmujacy dlugosc  prostopadloscianu
 */
  prism:: prism(  Vector<3> pkt0, double wysokosc, double szerokosc, double dlugosc)
 {
     for(int i=0;i< SIZE_PRISM;i++)
 point[i]=pkt0;
 point[1][0]+=szerokosc;

 point[2][1]+=wysokosc;

 point[3][0]+=szerokosc;
 point[3][1]+=wysokosc;

 point[4][1]+=wysokosc;
  point[4][2]+=dlugosc;

 point[5][0]+=szerokosc;
 point[5][1]+=wysokosc;
 point[5][2]+=dlugosc;

  point[6][2]+=dlugosc;

 point[7][0]+=szerokosc;
 point[7][2]+=dlugosc;
 }

/*!
 *  Funktor prostopadloscianu.                                                                                                                      
 * \param[in] index - index wektora.                                                                                                             
 * \retval Wartosc prostopadloscianu w danym miejscu tablicy.                              
 */
const   Vector<3> & prism::operator [] (int index) const
{
    return point[index];
}
/*!
 *  Funktor prostopadloscianu.                                                                                                                      
 * \param[in] index - index wektora.                                                                                                             
 * \retval Wartosc prostopadloscianu w danym miejscu tablicy.                              
 */
  Vector<3> & prism::operator [] (int index) 
{
return point[index];
}
/*!
*  Realizuje dodawanie Wektora do prostopadloscianu.                                                                      
 * \param[in]  move- drugi skladnik dodawania.                                         
  * \retval    Sume dwoch skladnikow wierzcholkow prostopadloscianu i wektora                                                                             
 */
 prism  prism::operator + (  Vector<3> move)
{
    
     prism wynik;
    for(int i=0;i< SIZE_PRISM;i++)
        wynik[i]=point[i]+move;
    return wynik;
    
}
/*!
*  Przeciazenie operatora <<                                                                                                               
 * \param[in]     out - strumien wejsciowy,                                             
 * \param[in]    tmp - prostokat.                                                         
 */
std::ostream &operator <<(std::ostream &out,const  prism &tmp )
{
    for(int i=0;i< SIZE_PRISM;i++)
    {
    out<<tmp[i]<<std::endl;
    if((i+1)%2==0)
      out<<std::endl;
    }
    out<<tmp[0]<<std::endl;
     out<<tmp[1]<<std::endl;
     return out;
}
/*!
*  funkcja przesowajaca prostopadloscian o dany wektor                                                                  
 * \param[in]  move- wektor translacjia.   
 * \param this - prostopadloscian                                     
  * \retval   prostopadloscian po przesunueciu                                                                          
 */
void  prism::move_r(  Vector<3> move)
{
    *this=*this+move;
}





