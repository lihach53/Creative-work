#pragma once
#include "Reader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <filesystem>
#include <cstdio>
#include <vcclr.h>

namespace liba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для ReaderForm
	/// </summary>
	public ref class ReaderForm : public System::Windows::Forms::Form
	{
	private: std::vector<std::string>* readers;
	private: System::Windows::Forms::ListBox^ info_list;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ search_line;
	private: System::Windows::Forms::Button^ search_button;
	private: System::Windows::Forms::Label^ label4;
		   List<String^>^ parts;
	public:
		ReaderForm(void)
		{
			InitializeComponent();
			readers = new std::vector<std::string>;
			LoadList();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ReaderForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ fio_textBox;
	protected:
	private: System::Windows::Forms::TextBox^ passNum_textBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ readerslistBox;
	private: System::Windows::Forms::Button^ Registr_button;
	private: System::Windows::Forms::Button^ delete_button;
	private: System::Windows::Forms::Button^ save_button;

	private: System::Windows::Forms::Button^ info_button;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ReaderForm::typeid));
			this->fio_textBox = (gcnew System::Windows::Forms::TextBox());
			this->passNum_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->readerslistBox = (gcnew System::Windows::Forms::ListBox());
			this->Registr_button = (gcnew System::Windows::Forms::Button());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->save_button = (gcnew System::Windows::Forms::Button());
			this->info_button = (gcnew System::Windows::Forms::Button());
			this->info_list = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->search_line = (gcnew System::Windows::Forms::TextBox());
			this->search_button = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// fio_textBox
			// 
			this->fio_textBox->Location = System::Drawing::Point(63, 34);
			this->fio_textBox->Name = L"fio_textBox";
			this->fio_textBox->Size = System::Drawing::Size(156, 20);
			this->fio_textBox->TabIndex = 0;
			// 
			// passNum_textBox
			// 
			this->passNum_textBox->Location = System::Drawing::Point(63, 60);
			this->passNum_textBox->Name = L"passNum_textBox";
			this->passNum_textBox->Size = System::Drawing::Size(156, 20);
			this->passNum_textBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"ФИО";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Паспорт";
			// 
			// readerslistBox
			// 
			this->readerslistBox->FormattingEnabled = true;
			this->readerslistBox->Location = System::Drawing::Point(8, 192);
			this->readerslistBox->Name = L"readerslistBox";
			this->readerslistBox->Size = System::Drawing::Size(719, 264);
			this->readerslistBox->TabIndex = 4;
			// 
			// Registr_button
			// 
			this->Registr_button->Location = System::Drawing::Point(107, 95);
			this->Registr_button->Name = L"Registr_button";
			this->Registr_button->Size = System::Drawing::Size(112, 23);
			this->Registr_button->TabIndex = 5;
			this->Registr_button->Text = L"Зарегестрировать";
			this->Registr_button->UseVisualStyleBackColor = true;
			this->Registr_button->Click += gcnew System::EventHandler(this, &ReaderForm::Registr_button_Click);
			// 
			// delete_button
			// 
			this->delete_button->Location = System::Drawing::Point(553, 462);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(85, 33);
			this->delete_button->TabIndex = 6;
			this->delete_button->Text = L"Удалить";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &ReaderForm::delete_button_Click);
			// 
			// save_button
			// 
			this->save_button->Location = System::Drawing::Point(642, 462);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(85, 33);
			this->save_button->TabIndex = 7;
			this->save_button->Text = L"Сохранить";
			this->save_button->UseVisualStyleBackColor = true;
			this->save_button->Click += gcnew System::EventHandler(this, &ReaderForm::save_button_Click);
			// 
			// info_button
			// 
			this->info_button->Location = System::Drawing::Point(8, 462);
			this->info_button->Name = L"info_button";
			this->info_button->Size = System::Drawing::Size(85, 33);
			this->info_button->TabIndex = 9;
			this->info_button->Text = L"Информация";
			this->info_button->UseVisualStyleBackColor = true;
			this->info_button->Click += gcnew System::EventHandler(this, &ReaderForm::info_button_Click);
			// 
			// info_list
			// 
			this->info_list->FormattingEnabled = true;
			this->info_list->Location = System::Drawing::Point(246, 33);
			this->info_list->Name = L"info_list";
			this->info_list->Size = System::Drawing::Size(481, 108);
			this->info_list->TabIndex = 10;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Registr_button);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->passNum_textBox);
			this->groupBox1->Controls->Add(this->fio_textBox);
			this->groupBox1->Location = System::Drawing::Point(8, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(232, 125);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Регистрация";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(433, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(124, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Информационное окно";
			// 
			// search_line
			// 
			this->search_line->Location = System::Drawing::Point(8, 160);
			this->search_line->Multiline = true;
			this->search_line->Name = L"search_line";
			this->search_line->Size = System::Drawing::Size(317, 23);
			this->search_line->TabIndex = 13;
			this->search_line->TextChanged += gcnew System::EventHandler(this, &ReaderForm::search_line_TextChanged);
			// 
			// search_button
			// 
			this->search_button->Location = System::Drawing::Point(331, 160);
			this->search_button->Name = L"search_button";
			this->search_button->Size = System::Drawing::Size(88, 23);
			this->search_button->TabIndex = 14;
			this->search_button->Text = L"Поиск";
			this->search_button->UseVisualStyleBackColor = true;
			this->search_button->Click += gcnew System::EventHandler(this, &ReaderForm::search_button_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Поиск";
			// 
			// ReaderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 500);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->search_button);
			this->Controls->Add(this->search_line);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->info_list);
			this->Controls->Add(this->info_button);
			this->Controls->Add(this->save_button);
			this->Controls->Add(this->delete_button);
			this->Controls->Add(this->readerslistBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ReaderForm";
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"АРМ";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Registr_button_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string fio = msclr::interop::marshal_as<std::string>(fio_textBox->Text);
		std::string passNum = msclr::interop::marshal_as<std::string>(passNum_textBox->Text);


		Reader reader(fio, passNum);
		std::string str = reader.toString();
		(*readers).push_back(str);
		
		//создание txt профиля каждого читателя
		std::string filename = "";
		std::wstring cyrillicDigits = L"0123456789";
		for (wchar_t c : str) {
			if (cyrillicDigits.find(c) != std::wstring::npos) {
				filename += c;
			}
		}
		std::string path = "users\\" + filename + ".txt";
		std::ofstream file(path);
		file.close();

		UpdateList();

		//Сохранение данных в Читатели.txt
		std::ofstream log("database\\Читатели.txt");

		for (int i = 0; i < readerslistBox->Items->Count; i++)
			log << msclr::interop::marshal_as<std::string>(readerslistBox->Items[i]->ToString()) << std::endl;

		log.close();
	}
	private: System::Void delete_button_Click(System::Object^ sender, System::EventArgs^ e) {
		int index = readerslistBox->SelectedIndex;
		int Size = (*readers).size();

		//УДАЛЕНИЕ TXT ПРОФИЛЬ ФАЙЛА
		std::string str = (*readers)[index];
		std::string filename = "";
		std::wstring cyrillicDigits = L"0123456789";
		for (wchar_t c : str) {
			if (cyrillicDigits.find(c) != std::wstring::npos) {
				filename += c;
			}
		}
		std::string path = "users\\" + filename + ".txt";
		std::remove(path.c_str());

		//УДАЛЕНИЕ ИЗ СПИСКА
		if (index >= 0 && index < Size)
		{
			(*readers).erase((*readers).begin() + index);
			UpdateList();
		}

		//СОХРАНЕНИЕ СПИСКА
		std::ofstream log("database\\Читатели.txt");

		for (int i = 0; i < readerslistBox->Items->Count; i++)
			log << msclr::interop::marshal_as<std::string>(readerslistBox->Items[i]->ToString()) << std::endl;

		log.close();

	}
	private: System::Void UpdateList() {
		readerslistBox->Items->Clear();
		for (int i = 0; i < (*readers).size(); i++)
			readerslistBox->Items->Add(msclr::interop::marshal_as<String^>((*readers)[i]));
	}
	private: void LoadList()
	{
		if (std::filesystem::exists("database\\Читатели.txt"))
		{
			std::ifstream file("database\\Читатели.txt");

			std::string str = "";

			while (getline(file, str)) {
				(*readers).push_back(str);
				readerslistBox->Items->Add(msclr::interop::marshal_as<String^>(str));
			}
			file.close();
		}
	}
private: System::Void save_button_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ofstream log("database\\Читатели.txt");

	for (int i = 0; i < readerslistBox->Items->Count; i++)
		log << msclr::interop::marshal_as<std::string>(readerslistBox->Items[i]->ToString()) << std::endl;

	log.close();
}
/*private: System::Void check_button_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < readerslistBox->Items->Count; i++) {
		Object^ selectedItemi = readerslistBox->Items[i];
		String^ selectedItem = dynamic_cast<String^>(selectedItemi);
		std::string str = msclr::interop::marshal_as<std::string>(selectedItem);
		std::string filename = "";
		std::wstring cyrillicDigits = L"0123456789";
		for (wchar_t c : str) {
			if (cyrillicDigits.find(c) != std::wstring::npos) {
				filename += c;
			}
		}
		std::string path = "users\\" + filename + ".txt";
		std::ifstream filePers(path);
		std::string str1;
		getline(filePers, str1);
		String^ str2 = msclr::interop::marshal_as<String^>(str1);

		array<String^>^ parts = str2->Split(';');
		DateTime dateTime;
		for (int j = 1; j < sizeof(parts); j += 2) {
			dateTime = DateTime::Parse(msclr::interop::marshal_as<String^>(parts[j]));
			//////////////////////////////////////////////////
		}
	}
}*/
private: System::Void info_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (info_list->Items->Count != 0) {
		info_list->Items->Clear();
	}
	int index = readerslistBox->SelectedIndex;
	std::string str = (*readers)[index];
	std::string filename = "";
	std::wstring cyrillicDigits = L"0123456789";
	for (wchar_t c : str) {
		if (cyrillicDigits.find(c) != std::wstring::npos) {
			filename += c;
		}
	}
	std::string path = "users\\" + filename + ".txt";
	std::ifstream filePers;
	filePers.open(path, std::ios::app);
	std::string books_;
	getline(filePers, books_);
	String^ books = msclr::interop::marshal_as<String^>(books_);
	parts = gcnew List<String^>(books->Split(';'));
	if (parts->Count - 1 != 0) {
		for (int i = 0; i < parts->Count - 1; i += 2) {
			info_list->Items->Add("Книга: " + parts[i]);
			info_list->Items->Add("Сдать до " + parts[i + 1] + "\n");
		}
	}
	else {
		info_list->Items->Add("Книг не зарегистрировано!");
	}
}
	private: System::Void search_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ searchQuery = search_line->Text; // Получение текста поискового запроса

		readerslistBox->Items->Clear(); // Очистка ListBox

		for (int i = 0; i < readerslistBox->Items->Count; i++) {
			String^ currentItem = readerslistBox->Items[i]->ToString();

			// Проверка, содержит ли текущая строка поисковый запрос
			if (currentItem->Contains(searchQuery)) {
				readerslistBox->Items->Add(currentItem); // Добавление строки в ListBox
			}
		}

		if (readerslistBox->Items->Count == 0) {
			MessageBox::Show("Совпадений не найдено.");
			UpdateList();
		}
	}
private: void FilterListBoxItems(ListBox ^ listBox, String ^ filterText){
	// Очистка текущего списка элементов
	listBox->Items->Clear();

	// Получение исходного списка элементов
	array<Object^>^ items = gcnew array<Object^>(listBox->Items->Count);
	listBox->Items->CopyTo(items, 0);

	// Проверка каждого элемента списка
	for each (Object ^ item in items)
	{
		// Приведение элемента списка к типу строки
		String^ itemText = dynamic_cast<String^>(item);

		// Проверка наличия неполного названия в элементе списка
		if (itemText->IndexOf(filterText, StringComparison::CurrentCultureIgnoreCase) >= 0)
		{
			// Добавление элемента в список, если неполное название найдено
			listBox->Items->Add(itemText);
		}
	}
}
private: System::Void search_line_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	// Приведение отправителя события к типу TextBox
	TextBox^ textBox = dynamic_cast<TextBox^>(sender);

	// Получение неполного названия для фильтрации
	String^ filterText = textBox->Text;

	// Вызов функции для фильтрации элементов ListBox
	FilterListBoxItems(readerslistBox, filterText);
}
};
}
