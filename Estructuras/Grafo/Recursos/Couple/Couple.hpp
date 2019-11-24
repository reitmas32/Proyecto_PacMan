/**!<Guardas de inclusión*/
#ifndef COUPLE_HPP
#define COUPLE_HPP

/**
 *@class Couple
 *@brief Tipo de dato que tiene una key por cada value
 */

template<typename First, typename Second>
class Couple{
	private:
		First key;
		Second value;
	public:

		/**
		 *@brief Método constructor de couple
		 *
		 *@param _key Clave de la couple
		 *
		 *@param _value Información que se quiere guardar
		 */ 
		Couple(First _key, Second _value);

		/**
		 *@brief Método constructor de couple
		 *
		 *@param _key Clave de la couple
		 */
		Couple(First _key);

		/**
		 *@brief Método destructor de couple
		 */
		~Couple();

		/**
		 *@brief Método que modifica el Value de una couple
		 */
		void setValue(Second _value);

		/**
		 *@brief Método que nos da la key de la couple
		 *
		 *@return La key asociada a la couple
		 */
		First getKey();

		/**
		 *@brief Método que nos da el value de la couple
		 *
		 *@return El value asociado a la couple
		 */
		Second getValue();

};

template<typename First, typename Second>
Couple<First,Second>::Couple(First _key, Second _value){
	key = _key;
	value = _value;
}

template<typename First, typename Second>
Couple<First,Second>::Couple(First _key){
	key = _key;
}

template<typename First, typename Second>
Couple<First,Second>::~Couple(){
	/*Destructor vacío*/
}

template<typename First, typename Second>
void Couple<First,Second>::setValue(Second _value){

	value = _value;
}

template<typename First, typename Second>
First Couple<First,Second>::getKey(){
	return key;
}

template<typename First, typename Second>
Second Couple<First,Second>::getValue(){
	return value;
}

#endif