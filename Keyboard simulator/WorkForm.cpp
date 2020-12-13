#include "WorkForm.h"
#include "LogUpForm.h"
#include "Functions.h"

#include <fstream>
#include <string>

System::Void Keyboardsimulator::WorkForm::назадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (start) {
		if (!complete) {
			if (MessageBox::Show("Тест был не завершен!\nПри выходе результат сохраниться.\nВернуться назад?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
				//Сохраняем результат
				SaveResult();

				//Переход назад
				LogUpForm^ form = gcnew LogUpForm();
				form->Show();
				this->Hide();
			}
		}
		else {
			//Переход назад
			LogUpForm^ form = gcnew LogUpForm();
			form->Show();
			this->Hide();
		}
	}
	else {
		//Переход назад
		LogUpForm^ form = gcnew LogUpForm();
		form->Show();
		this->Hide();
	}
}

System::Void Keyboardsimulator::WorkForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Программа предназначена для обучения работы с клавиатурой!", "Информация о программе!");
}

System::Void Keyboardsimulator::WorkForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (start) {
		if (!complete) {
			if (MessageBox::Show("Тест был не завершен!\nПри выходе результат сохраниться.\nВыйти?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
				//Сохраняем результат
				SaveResult();

				//Выход
				Application::Exit();
			}
		}
		else {
			//Выход
			Application::Exit();
		}
	}
	else {
		//Выход
		Application::Exit();
	}
}

System::Void Keyboardsimulator::WorkForm::buttonStart_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!start) {
		start = true;
		timer->Start();

		ResetParam();//обнулить параметры

		ShowWords();//показываем слова для ввода
	}
	else
	{
		if (MessageBox::Show("Тест запущен и не завершен!\nПри перезапуске результат сохраниться.\nПерезапустить?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
			//Сохраняем результат
			SaveResult();

			//Выход
			ResetParam();//обнулить параметры
		}
	}
}

System::Void Keyboardsimulator::WorkForm::buttonNext_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (complete) {
		MessageBox::Show("Тест был завершен!\nНачните снова!", "Внимание!");
		return;
	}

	//Проверка
	Check();
	
	ShowWords();//показываем слова для ввода
}

System::Void Keyboardsimulator::WorkForm::buttonComplete_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer->Stop();

	//Проверка
	Check();

	//Сохранения результата
	SaveResult();

	complete = true;
	start = false;
}

System::Void Keyboardsimulator::WorkForm::WorkForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	//Загружаем слова
	LoadData();

	MessageBox::Show("Для начала нажмите - Начать\nДля перехода далее нажмите - Продолжить\nДля завершения нажмите - Завершить","Внимание!");
}

void Keyboardsimulator::WorkForm::Update(System::Object^ sender, System::EventArgs^ e)
{
	time++;

	labelTimer->Text = "Время ввода: " + Convert::ToString(time);
}

void Keyboardsimulator::WorkForm::SaveResult()
{
	//Создаем поток дял записи
	std::ofstream save("SaveResult.txt", std::ios::app);

	std::string _name;
	Convert_String_to_string(name, _name);

	//Сохраняем результат
	save << "Имя пользователя: " << _name << std::endl;

	save << "Выбранная сложность: ";
	if(mode == 0)
		save << "простая" << std::endl;
	else if(mode == 1)
		save << "средняя" << std::endl;
	else 
		save << "сложная" << std::endl;

	save << "Количество тестов: " << in_total << std::endl;
	save << "Правильных вводов: " << correct_answers << std::endl;

	save << "Затраченное время на каждый ввод (в секундах): " << std::endl;
	for (int i = 0; i < times.Count; i++) {
		save << i+1 << ": " << times[i] << std::endl;
	}
	save << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;

	save.close();

	MessageBox::Show("Результат сохранен в файл: SaveResult.txt","Внимание!");
}

void Keyboardsimulator::WorkForm::LoadData()
{
	//Создаем поток для чтения 
	std::ifstream load("DataWords.txt");

	//Проверка файла
	if (!load) {
		MessageBox::Show("Ошибка открытия файла со словами!","Ошибка!");
		return;
	}

	//Временная переменная
	std::string bufs;
	String^ bufS;

	//Считываем все слова
	while (!load.eof())
	{
		load >> bufs;
		bufS = Convert_string_to_String(bufs, bufS);
		words.Add(bufS);
	}

	MessageBox::Show("Слова загружены из файла: DataWords.txt","Внимание!");
}

void Keyboardsimulator::WorkForm::ShowWords()
{
	//Очищаем текущий вывод
	textBoxOutput->Text = "";
	textBoxInput->Text = "";

	Random^ rand = gcnew Random();
	int count_words = 0;
	int index = 0;

	//Формируем строку слов
	if (mode == 0) {
		count_words = rand->Next(5, 10);//случайно определяем количество слов вывода		
	}
	else if (mode == 1) {
		count_words = rand->Next(10, 15);//случайно определяем количество слов вывода

	}
	else {
		count_words = rand->Next(15, 20);//случайно определяем количество слов вывода
	}

	for (int i = 0; i < count_words; i++) {
		index = rand->Next(0, words.Count - 1);//случайно определяем слово
		line_words += words[index];//запоминаем слова

		if (i < count_words - 1)
			line_words += " ";
	}

	//Выводим слова
	textBoxOutput->Text = line_words;
}

void Keyboardsimulator::WorkForm::ResetParam()
{
	complete = false;
	times.Clear();
	time = 0;
	correct_answers = 0;
	in_total = 0;
	line_words = "";
}

void Keyboardsimulator::WorkForm::Check()
{
	//Запоминаем результат времени ввода
	times.Add(time);
	in_total++;

	//Считываем строку ввода
	String^ input = textBoxInput->Text;

	//Проверяем введенную и сформированную строки
	if (input == line_words) {
		correct_answers++;
	}

	time = 0;
	line_words = "";
}
