#pragma once
#include "My_queue.h"
#include "Task.h"
#include "Processor.h"
#include "System.h"
#include "Main_form.h"

namespace Planning_process {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Start_form
	/// </summary>
	public ref class Start_form : public System::Windows::Forms::Form
	{
	public:
		Start_form(void)
		{
			InitializeComponent();
			count_cpu = 0;
			count_tasks = 0;
			is_next = false;
			step = 0;
			queue = new My_queue();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Start_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  set_cpu;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  set_tasks;
	private: System::Windows::Forms::Label^  check_automatic_difficult;
	private: System::Windows::Forms::Label^  check_manual_difficult;
	private: System::Windows::Forms::Button^  next_button;
	private: System::Windows::Forms::Label^  number_task_label;
	private: System::Windows::Forms::TextBox^  difficult_text;
	private: System::Windows::Forms::Label^  difficult_label;
	private:
		size_t count_cpu;// кол-во процессоров
		size_t count_tasks;// кол-во задач
		size_t step;// шаг инициализации
		bool is_next;
		My_queue *queue;// очередь задач
		task *current_task;// текущая задача
		processor *cpu;// указатель на массив процессоров
	private: System::Windows::Forms::Label^  ID_label;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  ID_text;
	private: System::Windows::Forms::Button^  exit_button;
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->set_cpu = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->set_tasks = (gcnew System::Windows::Forms::TextBox());
			this->check_automatic_difficult = (gcnew System::Windows::Forms::Label());
			this->check_manual_difficult = (gcnew System::Windows::Forms::Label());
			this->next_button = (gcnew System::Windows::Forms::Button());
			this->number_task_label = (gcnew System::Windows::Forms::Label());
			this->difficult_text = (gcnew System::Windows::Forms::TextBox());
			this->difficult_label = (gcnew System::Windows::Forms::Label());
			this->ID_label = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->ID_text = (gcnew System::Windows::Forms::TextBox());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(334, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(333, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выберите количество процессоров";
			// 
			// set_cpu
			// 
			this->set_cpu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->set_cpu->FormattingEnabled = true;
			this->set_cpu->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9",
					L"10", L"11", L"12"
			});
			this->set_cpu->Location = System::Drawing::Point(411, 94);
			this->set_cpu->Name = L"set_cpu";
			this->set_cpu->Size = System::Drawing::Size(177, 32);
			this->set_cpu->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(379, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(254, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Введите количество задач";
			// 
			// set_tasks
			// 
			this->set_tasks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->set_tasks->Location = System::Drawing::Point(454, 199);
			this->set_tasks->Name = L"set_tasks";
			this->set_tasks->Size = System::Drawing::Size(100, 29);
			this->set_tasks->TabIndex = 3;
			// 
			// check_automatic_difficult
			// 
			this->check_automatic_difficult->AutoSize = true;
			this->check_automatic_difficult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->check_automatic_difficult->Location = System::Drawing::Point(315, 297);
			this->check_automatic_difficult->Name = L"check_automatic_difficult";
			this->check_automatic_difficult->Size = System::Drawing::Size(378, 24);
			this->check_automatic_difficult->TabIndex = 4;
			this->check_automatic_difficult->Text = L"1. Автоматическая установка сложности";
			this->check_automatic_difficult->Click += gcnew System::EventHandler(this, &Start_form::check_automatic_difficult_Click);
			// 
			// check_manual_difficult
			// 
			this->check_manual_difficult->AutoSize = true;
			this->check_manual_difficult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->check_manual_difficult->Location = System::Drawing::Point(315, 332);
			this->check_manual_difficult->Name = L"check_manual_difficult";
			this->check_manual_difficult->Size = System::Drawing::Size(247, 24);
			this->check_manual_difficult->TabIndex = 5;
			this->check_manual_difficult->Text = L"2. Ручной ввод сложности";
			this->check_manual_difficult->Click += gcnew System::EventHandler(this, &Start_form::check_manual_difficult_Click);
			// 
			// next_button
			// 
			this->next_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->next_button->Location = System::Drawing::Point(805, 480);
			this->next_button->Name = L"next_button";
			this->next_button->Size = System::Drawing::Size(167, 49);
			this->next_button->TabIndex = 6;
			this->next_button->Text = L"Далее";
			this->next_button->UseVisualStyleBackColor = true;
			this->next_button->Click += gcnew System::EventHandler(this, &Start_form::next_button_Click);
			// 
			// number_task_label
			// 
			this->number_task_label->AutoSize = true;
			this->number_task_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->number_task_label->Location = System::Drawing::Point(12, 60);
			this->number_task_label->Name = L"number_task_label";
			this->number_task_label->Size = System::Drawing::Size(90, 24);
			this->number_task_label->TabIndex = 7;
			this->number_task_label->Text = L"Задача 1";
			this->number_task_label->Visible = false;
			// 
			// difficult_text
			// 
			this->difficult_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->difficult_text->Location = System::Drawing::Point(129, 135);
			this->difficult_text->Name = L"difficult_text";
			this->difficult_text->Size = System::Drawing::Size(57, 29);
			this->difficult_text->TabIndex = 8;
			this->difficult_text->Visible = false;
			// 
			// difficult_label
			// 
			this->difficult_label->AutoSize = true;
			this->difficult_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->difficult_label->Location = System::Drawing::Point(12, 138);
			this->difficult_label->Name = L"difficult_label";
			this->difficult_label->Size = System::Drawing::Size(111, 24);
			this->difficult_label->TabIndex = 9;
			this->difficult_label->Text = L"Сложность";
			this->difficult_label->Visible = false;
			// 
			// ID_label
			// 
			this->ID_label->AutoSize = true;
			this->ID_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ID_label->Location = System::Drawing::Point(12, 100);
			this->ID_label->Name = L"ID_label";
			this->ID_label->Size = System::Drawing::Size(27, 24);
			this->ID_label->TabIndex = 10;
			this->ID_label->Text = L"ID";
			this->ID_label->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(450, 262);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(111, 24);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Сложность";
			this->label5->Visible = false;
			// 
			// ID_text
			// 
			this->ID_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ID_text->Location = System::Drawing::Point(129, 97);
			this->ID_text->Name = L"ID_text";
			this->ID_text->Size = System::Drawing::Size(57, 29);
			this->ID_text->TabIndex = 12;
			this->ID_text->Visible = false;
			// 
			// exit_button
			// 
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exit_button->Location = System::Drawing::Point(12, 480);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(167, 49);
			this->exit_button->TabIndex = 13;
			this->exit_button->Text = L"Выход";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &Start_form::exit_button_Click);
			// 
			// Start_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 541);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->ID_text);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->ID_label);
			this->Controls->Add(this->difficult_label);
			this->Controls->Add(this->difficult_text);
			this->Controls->Add(this->number_task_label);
			this->Controls->Add(this->next_button);
			this->Controls->Add(this->check_manual_difficult);
			this->Controls->Add(this->check_automatic_difficult);
			this->Controls->Add(this->set_tasks);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->set_cpu);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Start_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Установка параметров";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//обработка события при выборе автоматической генерации сложности задачи
	private: System::Void check_automatic_difficult_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->check_automatic_difficult->ForeColor = System::Drawing::Color::Blue;
				 this->check_manual_difficult->ForeColor = System::Drawing::Color::Black;
	}
			 //обработка события при выборе ручного ввода сложности задачи
private: System::Void check_manual_difficult_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->check_automatic_difficult->ForeColor = System::Drawing::Color::Black;
			 this->check_manual_difficult->ForeColor = System::Drawing::Color::Blue;
}
		 // //обработка события перехода на главную форму
private: System::Void next_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 int ID;
			 int difficult;
			 if (!is_next)
			 {
				 is_next = true;
				 //конвертирование и инициализация введеных данных пользователем 
				 try
				 {
					 count_cpu = Convert::ToInt16(this->set_cpu->Text);
					 count_tasks = Convert::ToInt16(this->set_tasks->Text);
					 if (check_automatic_difficult->ForeColor != System::Drawing::Color::Blue&&
						 check_manual_difficult->ForeColor != System::Drawing::Color::Blue || count_cpu == 0 || count_tasks == 0)
					 {
						 throw;// бросается исклбчение в случае некорректности введенных данных
					 }
				 }
				 catch (Exception ^ex)
				 {
					 MessageBox::Show("Не верна введена информация\nВведите еще раз!", "Ошибка");
					 return;
				 }

				 cpu = new processor[count_cpu];// массив процессоров
				 for (size_t i = 0; i < count_cpu; i++)
				 {
					 cpu[i].set_number(i);
				 }
				 if (this->check_automatic_difficult->ForeColor == System::Drawing::Color::Blue)
				 {
					 // автоматическая генерация сложности задачи
					 Random ^rand = gcnew Random();
					 for (size_t i = 0; i < count_tasks; i++)
					 {
						 ID = i + 1;
						 difficult = rand->Next(1, 50);
						 current_task = new task(ID, difficult);
						 queue->push_back(current_task);
					 }
					 My_system *my_system = new My_system(queue, count_cpu, cpu);
					 Main_form ^form = gcnew Main_form(my_system);
					 // запуск главной формы после инициализации данных
					 this->Hide();
					 form->ShowDialog();
					 delete form;
					 //delete my_system;
					 this->Show();
				 }
				 else
				 {
					 //ручной ввод сложности
					 set_cpu->Visible = false;
					 set_tasks->Visible = false;
					 label1->Visible = false;
					 label2->Visible = false;
					 check_automatic_difficult->Visible = false;
					 check_manual_difficult->Visible = false;
					 number_task_label->Visible = true;
					 ID_label->Visible = true;
					 difficult_label->Visible = true;
					 ID_text->Visible = true;
					 difficult_text->Visible = true;
				 }
			 }
			 else
			 {
				 try
				 {
					 ID = Convert::ToInt32(this->ID_text->Text);
					 difficult = Convert::ToInt32(this->difficult_text->Text);
				 }
				 catch (Exception ^ex)
				 {
					 MessageBox::Show("Не верна введена информация\nВведите еще раз!", "Ошибка");
					 return;
				 }
				 step++;// переход к след шагу
				 current_task = new task(ID, difficult);// выделение памяти под новую задачу
				 queue->push_back(current_task);
				 number_task_label->Text = "Задача " + Convert::ToString(step + 1);
				 ID_text->Text = "";
				 difficult_text->Text = "";
				 if (step == count_tasks)
				 {
					 My_system *my_system = new My_system(queue, count_cpu, cpu);
					 Main_form ^form = gcnew Main_form(my_system);
					 // запуск главной формы
					 this->Hide();
					 form->ShowDialog();
					 if (form)
					 {
						 delete form;
					 }
					 Application::Exit();
				 }
			 }
}
		 // обработка события нажатия на кнопку выхода
private: System::Void exit_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (queue)
			 {
				 delete queue;
			 }
			 if (cpu)
			 {
				 delete[] cpu;
			 }
			 Application::Exit();
}
};
}
