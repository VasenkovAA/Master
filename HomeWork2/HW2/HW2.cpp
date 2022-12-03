#include <iostream>
struct Dimension { // шкаф (описывается габаритами)
	int height;
	int depth;
	int width;
};
// ввод параметров шкафа
void input(struct Dimension *sizes) {
	std::cout << "Input height: ";
	std::cin >> sizes->height;
	std::cout << "Input depth: ";
	std::cin >> sizes->depth;
	std::cout << "Input width: ";
	std::cin >> sizes->width;
}
// расчёт поверхности шкафа
int calculateSquare(struct Dimension sizes) {
	int square_bok, square_updown, square_front;
	// 2 боковые крышки
	square_bok = 2 * sizes.height * sizes.depth;
	// верхняя и нижняя крышки
	square_updown = 2 * sizes.width * sizes.depth;
	// 1 передняя крышка
	square_front = sizes.height * sizes.width;
	return (square_bok + square_updown + square_front);
	
}
// расчёт объёма шкафа
int calculateVolume(struct Dimension sizes) {
	int V = sizes.height * sizes.depth * sizes.width;
	return V;
}
// расчёт сколько краски нужно на весь шкаф
// consumption – расход краски на м2
float calculateDye(struct Dimension sizes, float consumption) {
	// с помощью написанной ранее функции вычисляем площадь поверхности
	int square = calculateSquare(sizes);
	// зная расход и площадь вычисляем сколько краски нужно
	float dye_needed = square * consumption;
	return dye_needed;
}
//расчет стоимости шкафа
void calculateCupboardCost(struct Dimension sizes, float cupboardCost) {

}

int main() {
	// расход краски, стоимость работы по покраске, стоимость краски
	float paintConsumption = 0.8, paintWorkCost = 35.00, paintCost = 50.00;
	// стоимость материала шкафа за м2
	float cupboardCost = 650;
	// вес кг/м2
	float weight = 0.9;
	// число этажей
	int floorsCount = 5;
	// float deliveryCost = 500.00;
	// float riseCost = 2.50;





}