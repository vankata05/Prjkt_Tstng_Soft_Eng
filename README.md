# FillArea



ТЕХНОЛОГИЧНО УЧИЛИЩЕ ЕЛЕКТРОННИ СИСТЕМИ към ТЕХНИЧЕСКИ УНИВЕРСИТЕТ - СОФИЯ

ПРОЕКТ ЗА ЛЯТНА ПРАКТИКА 10 КЛАС
Fill area

Реализирайте програма, която да може да:
Получава в конзолата име на файл, който съдържа изображение
Чете изображението
Запълва в черен цвят (0,0,0) дадена област





Представяне на изображението:
Дадена ви е структурата
struct pixel {
	char R;
	char G;
	char B;
};
Като всяко изображение представлява двумерен масив от този тип структури.
Във файла изображението е представено по следния начин:

3:3
R1:G1:B1 R2:G2:B2 R3:G3:B3
R4:G4:B4 R5:G5:B5 R6:G6:B6
R7:G7:B7 R8:G8:B8 R9:G9:B9

като Ri, Gi и Bi са произволни тройки от числа >=0 и <=255 (ВЪВ ФАЙЛА ТРЯБВА ДА ИМА ЦИФРИ НЕ БУКВИ!!!), разделени от “:”, тройките са разделени от спейсове, а първия ред представлява броя на редовете и колоните ( в случая 3 РЕДА И 3 КОЛОНИ)

Запълване на област от  изображението:
Областта представлява съседните по хоризонтала и вертикала пиксели, средната интензивност на цвета на които се различава най-много с единица. Средната интензивност е средно-аритметично от интензивностите на трите цветови канала - (R+G+B) / 3.

Изпълнение на програмата:
Прочитане на име на файл от конзолата
Прочитане на номер на ред и колона, които ще служат като координати  на областта, която ще се запълва.
Прочитане на файла и записването му в масив
Запълване на областта
Записване на промененото изображение във файла

Пример:
Подадени:
Файл, запълнен с 
2 4
20:20:200 15:180:10 
22:21:200 22:20:201
20:20:26 16:22:42
21:25:25 20:19:41

координати 1, 0 (ред 1, колона 0)

Резултат:
Файл, запълнен с 
2 4
0:0:0 15:180:10 
0:0:0 0:0:0
20:20:26 16:22:42
21:25:25 20:19:41


