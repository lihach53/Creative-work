#pragma once
#include "Book.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <filesystem>

namespace liba
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private: std::vector<std::string>* books;

	public:
		Form1(void)
		{
			InitializeComponent();
			books = new std::vector<std::string>;
			LoadList();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ titleTextBox;
	private: System::Windows::Forms::TextBox^ authorTextBox;
	private: System::Windows::Forms::TextBox^ publisherTextBox;
	private: System::Windows::Forms::TextBox^ yearTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::Button^ removeButton;
	private: System::Windows::Forms::ListBox^ booksListBox;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ save_button;
	private: System::Windows::Forms::TextBox^ searchTextBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label5;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Требуемый метод для поддержки конструктора — не изменяйте 
		   /// содержимое этого метода с помощью редактора кода.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			   this->titleTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->authorTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->publisherTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->yearTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->addButton = (gcnew System::Windows::Forms::Button());
			   this->removeButton = (gcnew System::Windows::Forms::Button());
			   this->booksListBox = (gcnew System::Windows::Forms::ListBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->save_button = (gcnew System::Windows::Forms::Button());
			   this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->groupBox1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // titleTextBox
			   // 
			   this->titleTextBox->Location = System::Drawing::Point(116, 31);
			   this->titleTextBox->Name = L"titleTextBox";
			   this->titleTextBox->Size = System::Drawing::Size(100, 20);
			   this->titleTextBox->TabIndex = 0;
			   // 
			   // authorTextBox
			   // 
			   this->authorTextBox->Location = System::Drawing::Point(116, 68);
			   this->authorTextBox->Name = L"authorTextBox";
			   this->authorTextBox->Size = System::Drawing::Size(100, 20);
			   this->authorTextBox->TabIndex = 1;
			   // 
			   // publisherTextBox
			   // 
			   this->publisherTextBox->Location = System::Drawing::Point(116, 110);
			   this->publisherTextBox->Name = L"publisherTextBox";
			   this->publisherTextBox->Size = System::Drawing::Size(100, 20);
			   this->publisherTextBox->TabIndex = 2;
			   // 
			   // yearTextBox
			   // 
			   this->yearTextBox->Location = System::Drawing::Point(116, 149);
			   this->yearTextBox->Name = L"yearTextBox";
			   this->yearTextBox->Size = System::Drawing::Size(100, 20);
			   this->yearTextBox->TabIndex = 3;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label1->Location = System::Drawing::Point(6, 32);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(67, 15);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Название:";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label2->Location = System::Drawing::Point(6, 73);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(45, 15);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"Автор:";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label3->Location = System::Drawing::Point(6, 111);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(94, 15);
			   this->label3->TabIndex = 6;
			   this->label3->Text = L"Издательство:";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label4->Location = System::Drawing::Point(6, 149);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(81, 15);
			   this->label4->TabIndex = 7;
			   this->label4->Text = L"Год выпуска:";
			   // 
			   // addButton
			   // 
			   this->addButton->Location = System::Drawing::Point(149, 190);
			   this->addButton->Name = L"addButton";
			   this->addButton->Size = System::Drawing::Size(67, 29);
			   this->addButton->TabIndex = 8;
			   this->addButton->Text = L"Добавить";
			   this->addButton->UseVisualStyleBackColor = true;
			   this->addButton->Click += gcnew System::EventHandler(this, &Form1::addButton_Click);
			   // 
			   // removeButton
			   // 
			   this->removeButton->Location = System::Drawing::Point(671, 341);
			   this->removeButton->Name = L"removeButton";
			   this->removeButton->Size = System::Drawing::Size(65, 29);
			   this->removeButton->TabIndex = 9;
			   this->removeButton->Text = L"Удалить";
			   this->removeButton->UseVisualStyleBackColor = true;
			   this->removeButton->Click += gcnew System::EventHandler(this, &Form1::removeButton_Click);
			   // 
			   // booksListBox
			   // 
			   this->booksListBox->Cursor = System::Windows::Forms::Cursors::Default;
			   this->booksListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->booksListBox->FormattingEnabled = true;
			   this->booksListBox->Location = System::Drawing::Point(250, 32);
			   this->booksListBox->Name = L"booksListBox";
			   this->booksListBox->Size = System::Drawing::Size(584, 303);
			   this->booksListBox->TabIndex = 10;
			   this->booksListBox->DoubleClick += gcnew System::EventHandler(this, &Form1::booksListBox_DoubleClick);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label5->Location = System::Drawing::Point(246, 9);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(76, 15);
			   this->label5->TabIndex = 11;
			   this->label5->Text = L"Список книг";
			   // 
			   // save_button
			   // 
			   this->save_button->Location = System::Drawing::Point(742, 341);
			   this->save_button->Name = L"save_button";
			   this->save_button->Size = System::Drawing::Size(80, 29);
			   this->save_button->TabIndex = 12;
			   this->save_button->Text = L"Сохранить";
			   this->save_button->UseVisualStyleBackColor = true;
			   this->save_button->Click += gcnew System::EventHandler(this, &Form1::save_button_Click);
			   // 
			   // searchTextBox
			   // 
			   this->searchTextBox->Location = System::Drawing::Point(6, 27);
			   this->searchTextBox->Name = L"searchTextBox";
			   this->searchTextBox->Size = System::Drawing::Size(237, 20);
			   this->searchTextBox->TabIndex = 13;
			   this->searchTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::searchTextBox_TextChanged);
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(12, 11);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(39, 13);
			   this->label6->TabIndex = 14;
			   this->label6->Text = L"Поиск";
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->yearTextBox);
			   this->groupBox1->Controls->Add(this->titleTextBox);
			   this->groupBox1->Controls->Add(this->authorTextBox);
			   this->groupBox1->Controls->Add(this->publisherTextBox);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Controls->Add(this->addButton);
			   this->groupBox1->Controls->Add(this->label3);
			   this->groupBox1->Controls->Add(this->label4);
			   this->groupBox1->Location = System::Drawing::Point(6, 97);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(237, 271);
			   this->groupBox1->TabIndex = 15;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Добавление";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(173, 53);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(70, 23);
			   this->button1->TabIndex = 16;
			   this->button1->Text = L"Поиск";
			   this->button1->UseVisualStyleBackColor = true;
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::White;
			   this->ClientSize = System::Drawing::Size(846, 380);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->searchTextBox);
			   this->Controls->Add(this->save_button);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->booksListBox);
			   this->Controls->Add(this->removeButton);
			   this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Name = L"Form1";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"АРМ";
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string title = msclr::interop::marshal_as<std::string>(titleTextBox->Text);
		std::string author = msclr::interop::marshal_as<std::string>(authorTextBox->Text);
		std::string publisher = msclr::interop::marshal_as<std::string>(publisherTextBox->Text);
		int year = Int32::Parse(yearTextBox->Text);

		Book book(title, author, publisher, year);
		std::string str = book.toString();
		(*books).push_back(str);

		UpdateList();

	}
	private: System::Void removeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int index = booksListBox->SelectedIndex;

		if (index >= 0 && index < (*books).size())
		{
			(*books).erase((*books).begin() + index);
			UpdateList();
		}
	}
	private: System::Void UpdateList() {
		booksListBox->Items->Clear();
		for (int i = 0; i < (*books).size(); i++)
			booksListBox->Items->Add(msclr::interop::marshal_as<String^>((*books)[i]));
	}
	private: void LoadList()
	{
		if (std::filesystem::exists("database\\библиотека.txt"))
		{
			std::ifstream file("database\\библиотека.txt");

			std::string str = "";

			while (getline(file, str)) {
				(*books).push_back(str);
				booksListBox->Items->Add(msclr::interop::marshal_as<String^>(str));
			}
			file.close();
		}
	}
	private: System::Void save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		std::ofstream log("database\\библиотека.txt");

		for (int i = 0; i < booksListBox->Items->Count; i++)
			log << msclr::interop::marshal_as<std::string>(booksListBox->Items[i]->ToString()) << std::endl;

		log.close();
	}
private: System::Void searchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	// Получение текущего текста из TextBox
	String^ searchText = searchTextBox->Text;

	// Очистка ListBox от предыдущих результатов поиска
	booksListBox->Items->Clear();

	// Проход по элементам ListBox и проверка наличия введенного текста поиска
	for (int i = 0; i < booksListBox->Items->Count; i++) {
		String^ itemText = booksListBox->Items[i]->ToString();

		// Если элемент содержит введенный текст, добавляем его в ListBox
		if (itemText->Contains(searchText)) {
			booksListBox->Items->Add(itemText);
		}
	}
}
private: System::Void booksListBox_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	std::string randomSector;
	std::string randomPolka;

	///СЕКТОР
	std::ifstream file("place\\sector.txt");
	if (file.is_open()) {
		std::vector<std::string> lines;
		std::string line;

		while (getline(file, line))
		{
			lines.push_back(line);
		}

		srand(static_cast<unsigned int>(time(0)));
		int randomIndex = rand() % lines.size();
		randomSector = lines[randomIndex];
		file.close();
	} 
	else
	{
		// файл не удалось открыть
		std::cout << "Не удалось открыть файл." << std::endl;
	}

	///ПОЛКА
	std::ifstream file2("place\\polka.txt");
	if (file2.is_open()) {
		std::vector<std::string> lines2;
		std::string line2;

		while (getline(file2, line2))
		{
			lines2.push_back(line2);
		}

		int randomIndex2 = rand() % lines2.size();
		randomPolka = lines2[randomIndex2];
		file2.close();
	}
	else {
		// файл не удалось открыть
		std::cout << "Не удалось открыть файл." << std::endl;
	}

	System::String^ randomLineString1 = msclr::interop::marshal_as<System::String^>(randomSector);
	System::String^ randomLineString2 = msclr::interop::marshal_as<System::String^>(randomPolka);
	MessageBox::Show("Сектор: " + randomLineString1 + "\n" + "\n" + "Полка: " + randomLineString2, "Местоположение");
}
};
}


/*	// Получение текущего текста из TextBox
	String^ searchText = searchTextBox->Text;

	// Очистка ListBox от предыдущих результатов поиска
	booksListBox->Items->Clear();

	// Проход по элементам ListBox и проверка наличия введенного текста поиска
	for (int i = 0; i < booksListBox->Items->Count; i++) {
		String^ itemText = booksListBox->Items[i]->ToString();

		// Если элемент содержит введенный текст, добавляем его в ListBox
		if (itemText->Contains(searchText)) {
			booksListBox->Items->Add(itemText);
		}
	}*/