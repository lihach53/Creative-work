#pragma once
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <filesystem>

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
	/// Сводка для AcceptForm
	/// </summary>
	static std::string Path2;
	public ref class AcceptForm : public System::Windows::Forms::Form
	{
	private: std::vector<std::string>* readers;
		   std::vector<std::string>* booki;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
		   List<String^>^ parts;
		   //System::Collections::Generic::List<String^>^ parts;
		   //array<String^>^ parts;
	public:
		AcceptForm(void)
		{
			InitializeComponent();
			readers = new std::vector<std::string>;
			booki = new std::vector<std::string>;
			//parts = gcnew System::Collections::Generic::List<String^>();
			LoadListPerson();
			groupBox1->Enabled = false;

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AcceptForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ reader_listBox7;
	protected:
	private: System::Windows::Forms::GroupBox^ accepr_groupBox;
	private: System::Windows::Forms::Button^ choosePers_button;
	private: System::Windows::Forms::ListBox^ book_list;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ accept_button;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AcceptForm::typeid));
			this->reader_listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->accepr_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->choosePers_button = (gcnew System::Windows::Forms::Button());
			this->book_list = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->accept_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->accepr_groupBox->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// reader_listBox7
			// 
			this->reader_listBox7->FormattingEnabled = true;
			this->reader_listBox7->Location = System::Drawing::Point(15, 37);
			this->reader_listBox7->Name = L"reader_listBox7";
			this->reader_listBox7->Size = System::Drawing::Size(209, 238);
			this->reader_listBox7->TabIndex = 0;
			// 
			// accepr_groupBox
			// 
			this->accepr_groupBox->Controls->Add(this->label1);
			this->accepr_groupBox->Controls->Add(this->choosePers_button);
			this->accepr_groupBox->Controls->Add(this->reader_listBox7);
			this->accepr_groupBox->Location = System::Drawing::Point(12, 12);
			this->accepr_groupBox->Name = L"accepr_groupBox";
			this->accepr_groupBox->Size = System::Drawing::Size(244, 318);
			this->accepr_groupBox->TabIndex = 1;
			this->accepr_groupBox->TabStop = false;
			this->accepr_groupBox->Text = L"Читатели";
			// 
			// choosePers_button
			// 
			this->choosePers_button->Location = System::Drawing::Point(15, 281);
			this->choosePers_button->Name = L"choosePers_button";
			this->choosePers_button->Size = System::Drawing::Size(209, 26);
			this->choosePers_button->TabIndex = 1;
			this->choosePers_button->Text = L"Выбрать";
			this->choosePers_button->UseVisualStyleBackColor = true;
			this->choosePers_button->Click += gcnew System::EventHandler(this, &AcceptForm::choosePers_button_Click);
			// 
			// book_list
			// 
			this->book_list->FormattingEnabled = true;
			this->book_list->Location = System::Drawing::Point(6, 37);
			this->book_list->Name = L"book_list";
			this->book_list->Size = System::Drawing::Size(558, 238);
			this->book_list->TabIndex = 2;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->accept_button);
			this->groupBox1->Controls->Add(this->book_list);
			this->groupBox1->Location = System::Drawing::Point(262, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(573, 318);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Книги";
			// 
			// accept_button
			// 
			this->accept_button->Location = System::Drawing::Point(6, 281);
			this->accept_button->Name = L"accept_button";
			this->accept_button->Size = System::Drawing::Size(558, 26);
			this->accept_button->TabIndex = 3;
			this->accept_button->Text = L"Принять";
			this->accept_button->UseVisualStyleBackColor = true;
			this->accept_button->Click += gcnew System::EventHandler(this, &AcceptForm::accept_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(59, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Выберите читателя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(217, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Выберите книгу";
			// 
			// AcceptForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 337);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->accepr_groupBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AcceptForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"АРМ";
			this->accepr_groupBox->ResumeLayout(false);
			this->accepr_groupBox->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void LoadListPerson()
	{
		if (std::filesystem::exists("database\\Читатели.txt"))
		{
			std::ifstream file("database\\Читатели.txt");

			std::string str = "";

			while (getline(file, str)) {
				(*readers).push_back(str);
				reader_listBox7->Items->Add(msclr::interop::marshal_as<String^>(str));
			}
			file.close();
		}
	}
	public: void Pathtxt(std::string path) {
		Path2 = path;
	}

	private: System::Void choosePers_button_Click(System::Object^ sender, System::EventArgs^ e) {
		int index = reader_listBox7->SelectedIndex;
		std::string str = (*readers)[index];
		std::string filename = "";
		std::wstring cyrillicDigits = L"0123456789";
		for (wchar_t c : str) {
			if (cyrillicDigits.find(c) != std::wstring::npos) {
				filename += c;
			}
		}
		std::string path = "users\\" + filename + ".txt";
		Pathtxt(path);
		std::ifstream filePers;
		filePers.open(path, std::ios::app);
		std::string books_;
		getline(filePers, books_);
		String^ books = msclr::interop::marshal_as<String^>(books_);
		parts = gcnew List<String^>(books->Split(';'));
		for (int i = 0; i < parts->Count-1; i += 2) {

			book_list->Items->Add(parts[i]);
		}
		if (book_list->Items->Count == 0) {
			MessageBox::Show("Книг не зарегестрировано");
		}
		else {
			accepr_groupBox->Enabled = false;
			groupBox1->Enabled = true;
		}
	}

private: System::Void accept_button_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ selectedItem = book_list->SelectedItem->ToString();
	book_list->Items->RemoveAt(book_list->SelectedIndex);
	std::ofstream fileReader("database\\библиотека.txt", std::ios::app);
	std::string strSelItem = marshal_as<std::string>(selectedItem);
	fileReader << strSelItem;
	fileReader.close();
	for (int i = 0; i < parts->Count; i++) {
		if (parts[i] == selectedItem){
			parts->RemoveAt(i + 1);
			parts->RemoveAt(i);
		}
	}
	std::ofstream file(Path2);
	std::string strPart;
	for (int i = 0; i < parts->Count; i++) {
		strPart = marshal_as<std::string>(parts[i]);
		file << strPart + ";";
	}
	file.close();
	if (book_list->Items->Count == 0) {
		accepr_groupBox->Enabled = true;
		groupBox1->Enabled = false;
		MessageBox::Show("Книг больше не зарегестрировано");
	}
	else {
		accepr_groupBox->Enabled = false;
		groupBox1->Enabled = true;
	}
	}
	};
}


/*	private: System::Void choosePers_button_Click(System::Object^ sender, System::EventArgs^ e) {
		int index = reader_listBox7->SelectedIndex;
		std::string str = (*readers)[index];
		std::string filename = "";
		std::wstring cyrillicDigits = L"0123456789";
		for (wchar_t c : str) {
			if (cyrillicDigits.find(c) != std::wstring::npos) {
				filename += c;
			}
		}
		std::string path = "users\\" + filename + ".txt";
		Pathtxt(path);
		std::ifstream filePers;
		filePers.open(path, std::ios::app);
		std::string books_;
		getline(filePers, books_);
		String^ books = msclr::interop::marshal_as<String^>(books_);
		//List<String^>^ parts = gcnew List<String^>(books->Split(';'));
		array<String^>^ parts = books->Split(';');
		std::string part;
		for (int i = 0; i < parts->Length; i += 2) {
			book_list->Items->Add(parts[i]);
		}
		accepr_groupBox->Enabled = false; 
	}*/