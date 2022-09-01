#include <iostream>
#include <string>

/*forgings_calculator - Калькулятор поковок*/

/*В данной версии программа считает поковки без механической 
 * обработки или с механической обработкой*/

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    
    // Переменные для ввода данных от пользователя
    float kilogram_of_ingot; // стоимость одного килограмма стального слитка
    float delivery_of_the_ingot; // стоимость доставки килограмма слитка
    float ingot_reforging_coefficient; // коэффициент перекова одного килограмма слитка
    float reforging_forgings; // стоимость перекова одного килограмма поковки
    float heat_treatment; // термообработка одного килограмма поковки
    float weight_of_one_forging; // вес одной поковки
    float number_of_forgings; // количество поковок
    float delivery_of_goods; // стоимость доставки товара
    float value_added_tax; // налог на добавленную стоимость - НДС - VAT
    float machining_of_one_kilogram_of_forgings; // стоимость механической обработки килограмма поковки
    
    char choice_of_machining; /*переменная управляет выбором наличия или отсутствия механической
    обработки в заказе*/
    
    // Объясняем пользователю возможности программы
    cout << "Здравствуйте, уважаемый пользователь!\n";
    cout << "Это Калькулятор поковок!\n";
    cout << "Вы можете подсчтитать стоимость поковок в заказе клиента!\n";
    cout << "Есть ли необходимость в механической обработке? Если да, введите \"y\", если нет, введите \"n\": ";
    cin >> choice_of_machining;
    
    if(choice_of_machining == 'y'){
        cout << "В вашем закзе поковкам требуется механическая обработка.\n";
        
        // Просим пользователя ввести данные
        cout << "Для получения результата, введите следующие данные:\n";
        cout << "1) вес одной поковки: ";
        cin >> weight_of_one_forging;
        cout << "2) стоимость одного килограмма стального слитка: ";
        cin >> kilogram_of_ingot;
        cout << "3) стоимость доставки килограмма слитка: ";
        cin >> delivery_of_the_ingot;
        cout << "4) коэффициент перекова одного килограмма слитка: ";
        cin >> ingot_reforging_coefficient;
        cout << "5) стоимость перекова одного килограмма поковки: ";
        cin >> reforging_forgings;
        cout << "6) термообработка одного килограмма поковки: ";
        cin >> heat_treatment;
        cout << "7) количество поковок: ";
        cin >> number_of_forgings;
        cout << "8) стоимость доставки товара до клиента без НДС: ";
        cin >> delivery_of_goods;
        cout << "9) введите ставку НДС введите десятичной дроби: ";
        cin >> value_added_tax;
        cout << "10) стоимость механической обработки килограмма поковки: ";
        cin >> machining_of_one_kilogram_of_forgings;
    
        // Результирующие переменные
        float total_weight_of_forgings = weight_of_one_forging * number_of_forgings; // общий вес поковок
        int machining_of_one_forging = machining_of_one_kilogram_of_forgings * weight_of_one_forging; /*
        стоимость механической обработки одной поковки*/
        float the_final_value_of_the_ingot = kilogram_of_ingot + delivery_of_the_ingot; /*итоговая 
        стоимость килограмма слитка*/
        float the_cost_of_a_reforged_ingot = the_final_value_of_the_ingot / ingot_reforging_coefficient; /*стоимость 
        килограмма слитка с перековом*/
        int one_forging_with_machining = ((the_cost_of_a_reforged_ingot + reforging_forgings + heat_treatment) * weight_of_one_forging) + machining_of_one_forging; /*
        стоимость одной поковки с механической обработкой*/
        int total_cost_of_forgings_with_machining = one_forging_with_machining * number_of_forgings; /*Общая стоимость
        поковок с механической обработкой без доставки и НДС*/
        int the_cost_of_the_batch_with_delivery = total_cost_of_forgings_with_machining + delivery_of_goods; /*стоимость партии 
        с доставкой до клиента без НДС*/
        int the_cost_of_the_batch_with_delivery_with_VAT = the_cost_of_the_batch_with_delivery * value_added_tax; /*
        cтоимость партии с доставкой до клиента c НДС*/
    
        // Вывод результата
        cout << "--------------------------\n";
        cout << "Ваш результат:\n";
        cout << "1) общий вес поковок: " << total_weight_of_forgings << " кг\n";
        cout << "2) стоимость механической обработки одной поковки: " << machining_of_one_forging << " рублей без НДС\n";
        cout << "3) стоимость одной поковки c механической обработкой: " << one_forging_with_machining << " рублей без НДС\n";
        cout << "4) общая стоимость поковок с механической обработкой: " << total_cost_of_forgings_with_machining << " рублей без НДС\n";
        cout << "5) общая стоимость поковок с механической обработкой с доставкой: " << the_cost_of_the_batch_with_delivery << " рублей без НДС\n";
        cout << "6) итоговая стоимость заказа: " << the_cost_of_the_batch_with_delivery_with_VAT << " рублей с НДС\n";
        cout << "---------------------------\n";
    } else if(choice_of_machining == 'n'){
        cout << "В вашем закзе поковкам не требуется механическая обработка.\n";
        // Просим пользователя ввести данные
        cout << "Для получения результата, введите следующие данные:\n";
        cout << "1) вес одной поковки: ";
        cin >> weight_of_one_forging;
        cout << "2) стоимость одного килограмма стального слитка: ";
        cin >> kilogram_of_ingot;
        cout << "3) стоимость доставки килограмма слитка: ";
        cin >> delivery_of_the_ingot;
        cout << "4) коэффициент перекова одного килограмма слитка: ";
        cin >> ingot_reforging_coefficient;
        cout << "5) стоимость перекова одного килограмма поковки: ";
        cin >> reforging_forgings;
        cout << "6) термообработка одного килограмма поковки: ";
        cin >> heat_treatment;
        cout << "7) количество поковок: ";
        cin >> number_of_forgings;
        cout << "8) стоимость доставки товара до клиента без НДС: ";
        cin >> delivery_of_goods;
        cout << "9) введите ставку НДС введите десятичной дроби: ";
        cin >> value_added_tax;
        
        
        // Результирующие переменные
        float total_weight_of_forgings = weight_of_one_forging * number_of_forgings; // общий вес поковок
        float the_final_value_of_the_ingot = kilogram_of_ingot + delivery_of_the_ingot; /*итоговая 
        стоимость килограмма слитка*/
        float the_cost_of_a_reforged_ingot = the_final_value_of_the_ingot / ingot_reforging_coefficient; /*стоимость 
        килограмма слитка с перековом*/
        int one_forging_without_machining = (the_cost_of_a_reforged_ingot + reforging_forgings + heat_treatment) * weight_of_one_forging; /*
        стоимость одной поковки без механической обработки*/
        int total_cost_of_forgings_without_machining = one_forging_without_machining * number_of_forgings; /*Общая стоимость
        поковок без механической обработки без доставки и НДС*/
        int the_cost_of_the_batch_with_delivery = total_cost_of_forgings_without_machining + delivery_of_goods; /*стоимость партии 
        с доставкой до клиента без НДС*/
        int the_cost_of_the_batch_with_delivery_with_VAT = the_cost_of_the_batch_with_delivery * value_added_tax; /*
        cтоимость партии с доставкой до клиента c НДС*/
        
        // Вывод результата
        cout << "--------------------------\n";
        cout << "Ваш результат:\n";
        cout << "1) общий вес поковок: " << total_weight_of_forgings << " кг\n";
        cout << "2) стоимость одной поковки без механической обработки: " << one_forging_without_machining << " рублей без НДС\n";
        cout << "3) общая стоимость поковок без механической обработки: " << total_cost_of_forgings_without_machining << " рублей без НДС\n";
        cout << "4) общая стоимость поковок без механической обработки с доставкой: " << the_cost_of_the_batch_with_delivery << " рублей без НДС\n";
        cout << "5) итоговая стоимость заказа: " << the_cost_of_the_batch_with_delivery_with_VAT << " рублей с НДС\n";
        cout << "---------------------------\n";
    }
    
    return 0;
}
