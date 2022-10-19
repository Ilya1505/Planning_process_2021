#pragma once
#include "My_queue.h"
#include "Task.h"
#include "Processor.h"
#include "System.h"
#include "Queue_form.h"

namespace Planning_process {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Main_form
	/// </summary>
	public ref class Main_form : public System::Windows::Forms::Form
	{
	public:
		Main_form(My_system *my_system)
		{
			this->my_system = my_system;
			InitializeComponent();
			this->my_system->setup();
			is_finish = false;
			minut = 0;
			sekond = 0;
			form_general_task = gcnew Queue_form(my_system, 1);
			form_block_task = gcnew Queue_form(my_system, 2);
			form_finish_task = gcnew Queue_form(my_system, 3);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main_form()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		bool is_finish;
		My_system *my_system;//  указатель на объект системы
		int minut;// минуты
		int sekond;// секунды
		Queue_form ^form_general_task;// указатель на форму с главной очередью задач
		Queue_form ^form_block_task;// указатель на форму с заблокированных задач
		Queue_form ^form_finish_task;// указатель на форму с завершенных задач

	private: System::Windows::Forms::DataGridView^  dataGridView;

	private: System::Windows::Forms::Label^  state_system_label;
	private: System::Windows::Forms::Label^  time_work_label;
	private: System::Windows::Forms::Button^  exit_button;

	private: System::Windows::Forms::Button^  pause_button;
	private: System::Windows::Forms::Button^  block_task_button;


	private: System::Windows::Forms::Button^  queue_button;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cpu_number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  procent_finish;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID_task;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  difficult;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  count_finish_tasks;
	private: System::Windows::Forms::DataGridViewButtonColumn^  block_task;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Label^  count_finish_tasks_label;
	private: System::Windows::Forms::Label^  count_task_label;
	private: System::Windows::Forms::Button^  finish_task_button;
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->cpu_number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->procent_finish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ID_task = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->difficult = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->count_finish_tasks = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->block_task = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->state_system_label = (gcnew System::Windows::Forms::Label());
			this->time_work_label = (gcnew System::Windows::Forms::Label());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->pause_button = (gcnew System::Windows::Forms::Button());
			this->block_task_button = (gcnew System::Windows::Forms::Button());
			this->queue_button = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->count_finish_tasks_label = (gcnew System::Windows::Forms::Label());
			this->count_task_label = (gcnew System::Windows::Forms::Label());
			this->finish_task_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->cpu_number,
					this->procent_finish, this->ID_task, this->difficult, this->count_finish_tasks, this->block_task
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView->GridColor = System::Drawing::SystemColors::Control;
			this->dataGridView->Location = System::Drawing::Point(0, -1);
			this->dataGridView->Name = L"dataGridView";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView->RowHeadersVisible = false;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dataGridView->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridView->RowTemplate->DefaultCellStyle->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->RowTemplate->Height = 30;
			this->dataGridView->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->Size = System::Drawing::Size(983, 410);
			this->dataGridView->TabIndex = 0;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Main_form::dataGridView_CellContentClick);
			// 
			// cpu_number
			// 
			this->cpu_number->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->cpu_number->Frozen = true;
			this->cpu_number->HeaderText = L"CPU №";
			this->cpu_number->Name = L"cpu_number";
			this->cpu_number->ReadOnly = true;
			this->cpu_number->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->cpu_number->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// procent_finish
			// 
			this->procent_finish->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->procent_finish->Frozen = true;
			this->procent_finish->HeaderText = L"% завершения задачи";
			this->procent_finish->Name = L"procent_finish";
			this->procent_finish->ReadOnly = true;
			this->procent_finish->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->procent_finish->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->procent_finish->Width = 250;
			// 
			// ID_task
			// 
			this->ID_task->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->ID_task->Frozen = true;
			this->ID_task->HeaderText = L"ID задачи";
			this->ID_task->Name = L"ID_task";
			this->ID_task->ReadOnly = true;
			this->ID_task->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->ID_task->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ID_task->Width = 150;
			// 
			// difficult
			// 
			this->difficult->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->difficult->Frozen = true;
			this->difficult->HeaderText = L"Сложность";
			this->difficult->Name = L"difficult";
			this->difficult->ReadOnly = true;
			this->difficult->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->difficult->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->difficult->Width = 120;
			// 
			// count_finish_tasks
			// 
			this->count_finish_tasks->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->count_finish_tasks->Frozen = true;
			this->count_finish_tasks->HeaderText = L"количество выполненных задач";
			this->count_finish_tasks->Name = L"count_finish_tasks";
			this->count_finish_tasks->ReadOnly = true;
			this->count_finish_tasks->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->count_finish_tasks->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->count_finish_tasks->Width = 200;
			// 
			// block_task
			// 
			this->block_task->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->block_task->Frozen = true;
			this->block_task->HeaderText = L"Блокировка задачи";
			this->block_task->Name = L"block_task";
			this->block_task->Width = 163;
			// 
			// state_system_label
			// 
			this->state_system_label->AutoSize = true;
			this->state_system_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->state_system_label->Location = System::Drawing::Point(8, 412);
			this->state_system_label->Name = L"state_system_label";
			this->state_system_label->Size = System::Drawing::Size(251, 24);
			this->state_system_label->TabIndex = 1;
			this->state_system_label->Text = L"Состояние системы: пауза";
			// 
			// time_work_label
			// 
			this->time_work_label->AutoSize = true;
			this->time_work_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->time_work_label->Location = System::Drawing::Point(8, 436);
			this->time_work_label->Name = L"time_work_label";
			this->time_work_label->Size = System::Drawing::Size(256, 24);
			this->time_work_label->TabIndex = 2;
			this->time_work_label->Text = L"Время работы системы: 0:0";
			// 
			// exit_button
			// 
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exit_button->Location = System::Drawing::Point(822, 488);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(150, 41);
			this->exit_button->TabIndex = 3;
			this->exit_button->Text = L"Выход";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &Main_form::exit_button_Click);
			// 
			// pause_button
			// 
			this->pause_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pause_button->Location = System::Drawing::Point(625, 488);
			this->pause_button->Name = L"pause_button";
			this->pause_button->Size = System::Drawing::Size(150, 41);
			this->pause_button->TabIndex = 4;
			this->pause_button->Text = L"Запуск";
			this->pause_button->UseVisualStyleBackColor = true;
			this->pause_button->Click += gcnew System::EventHandler(this, &Main_form::pause_button_Click);
			// 
			// block_task_button
			// 
			this->block_task_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->block_task_button->Location = System::Drawing::Point(220, 488);
			this->block_task_button->Name = L"block_task_button";
			this->block_task_button->Size = System::Drawing::Size(150, 41);
			this->block_task_button->TabIndex = 5;
			this->block_task_button->Text = L"Блок. процессы";
			this->block_task_button->UseVisualStyleBackColor = true;
			this->block_task_button->Click += gcnew System::EventHandler(this, &Main_form::button3_Click);
			// 
			// queue_button
			// 
			this->queue_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->queue_button->Location = System::Drawing::Point(12, 488);
			this->queue_button->Name = L"queue_button";
			this->queue_button->Size = System::Drawing::Size(150, 41);
			this->queue_button->TabIndex = 6;
			this->queue_button->Text = L"Очередь";
			this->queue_button->UseVisualStyleBackColor = true;
			this->queue_button->Click += gcnew System::EventHandler(this, &Main_form::queue_button_Click);
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &Main_form::timer_Tick);
			// 
			// count_finish_tasks_label
			// 
			this->count_finish_tasks_label->AutoSize = true;
			this->count_finish_tasks_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->count_finish_tasks_label->Location = System::Drawing::Point(575, 436);
			this->count_finish_tasks_label->Name = L"count_finish_tasks_label";
			this->count_finish_tasks_label->Size = System::Drawing::Size(268, 24);
			this->count_finish_tasks_label->TabIndex = 7;
			this->count_finish_tasks_label->Text = L"Число выполненных задач: 0";
			// 
			// count_task_label
			// 
			this->count_task_label->AutoSize = true;
			this->count_task_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->count_task_label->Location = System::Drawing::Point(575, 412);
			this->count_task_label->Name = L"count_task_label";
			this->count_task_label->Size = System::Drawing::Size(125, 24);
			this->count_task_label->TabIndex = 8;
			this->count_task_label->Text = L"Число задач:";
			// 
			// finish_task_button
			// 
			this->finish_task_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->finish_task_button->Location = System::Drawing::Point(422, 488);
			this->finish_task_button->Name = L"finish_task_button";
			this->finish_task_button->Size = System::Drawing::Size(150, 41);
			this->finish_task_button->TabIndex = 9;
			this->finish_task_button->Text = L"Выполненные процессы";
			this->finish_task_button->UseVisualStyleBackColor = true;
			this->finish_task_button->Click += gcnew System::EventHandler(this, &Main_form::finish_task_button_Click);
			// 
			// Main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 541);
			this->Controls->Add(this->finish_task_button);
			this->Controls->Add(this->count_task_label);
			this->Controls->Add(this->count_finish_tasks_label);
			this->Controls->Add(this->queue_button);
			this->Controls->Add(this->block_task_button);
			this->Controls->Add(this->pause_button);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->time_work_label);
			this->Controls->Add(this->state_system_label);
			this->Controls->Add(this->dataGridView);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Main_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Обработка процессов";
			this->Load += gcnew System::EventHandler(this, &Main_form::Main_form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//вывод формы с очередью задач, готовых к выполнению
	private: System::Void queue_button_Click(System::Object^  sender, System::EventArgs^  e) {
					 form_general_task->Show();

	}
			 // метод загрузки главной формы и инициализации объектов
private: System::Void Main_form_Load(System::Object^  sender, System::EventArgs^  e) {
			 dataGridView->AllowUserToAddRows = false;
			 String ^ID_task=gcnew String("NULL");;
			 String ^difficult_task = gcnew String("NULL");
			 // вывод данных в таблицу
			 for (size_t i = 0; i < my_system->get_count_cpu(); i++)
			 {
				 if (my_system->get_cpu(i)->get_task())
				 {
					 ID_task = Convert::ToString(my_system->get_cpu(i)->get_task()->get_ID());
					 difficult_task = Convert::ToString(my_system->get_cpu(i)->get_task()->get_difficult());
				 }
				 else
				 {
					 ID_task = "NULL";
					 difficult_task = "NULL";
				 }
				 dataGridView->Rows->Add(Convert::ToString(my_system->get_cpu(i)->get_number() + 1),
					 Convert::ToString(my_system->get_cpu(i)->get_current_procent())+"%",
					 ID_task,
					 difficult_task,
					 Convert::ToString(my_system->get_cpu(i)->get_count_completed()), "Блокировка");
			 }
			 delete ID_task;
			 delete difficult_task;
			 this->count_task_label->Text = "Число задач: " + Convert::ToString(my_system->get_count_tasks());
}
		 // нажатие на кнопку паузы
private: System::Void pause_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->pause_button->Text == "Запуск")
			 {
				 this->timer->Enabled = true;
				 my_system->start();
				 this->pause_button->Text = "Пауза";
				 state_system_label->Text = "Состояние системы: работа";
			 }
			 else
			 {
				 this->timer->Enabled = false;
				 my_system->pause();
				 this->pause_button->Text = "Запуск";
				 state_system_label->Text = "Состояние системы: пауза";
			 }
}
		 // обработка события на тик таймера
private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 // вызов метода work и проверка на завершение работы
			 if (my_system->work())
			 {
				 is_finish = true;
			 }
			 dataGridView->Rows->Clear();
			 String ^ID_task = gcnew String("NULL");;
			 String ^difficult_task = gcnew String("NULL");
			 // вывод новых данных в таблицу
			 for (size_t i = 0; i < my_system->get_count_cpu(); i++)
			 {
				 if (my_system->get_cpu(i)->get_task())
				 {
					 ID_task = Convert::ToString(my_system->get_cpu(i)->get_task()->get_ID());
					 difficult_task = Convert::ToString(my_system->get_cpu(i)->get_task()->get_difficult());
				 }
				 else
				 {
					 ID_task = "NULL";
					 difficult_task = "NULL";
				 }
				 dataGridView->Rows->Add(Convert::ToString(my_system->get_cpu(i)->get_number() + 1),
					 Convert::ToString(my_system->get_cpu(i)->get_current_procent())+"%",
					 ID_task,
					 difficult_task,
					 Convert::ToString(my_system->get_cpu(i)->get_count_completed()), "Блокировка");
			 }
			 delete ID_task;
			 delete difficult_task;
			 // обработка секундомера
			 sekond++;
			 if (sekond == 60)
			 {
				 minut++;
				 sekond = 0;
			 }
			 time_work_label->Text = "Время работы системы: " + Convert::ToString(minut) + " мин : " + Convert::ToString(sekond)+" сек";
			 count_finish_tasks_label->Text = "Число выполненных задач: " + Convert::ToString(my_system->get_count_finish_tasks());
			 form_general_task->time_tick();
			 form_block_task->time_tick();
			 form_finish_task->time_tick();
			 //если работа завершена
			 if (is_finish)
			 {
				 this->timer->Enabled = false;
				 state_system_label->Text = "Состояние системы: работа завершена";
				 form_finish_task->Hide();
				 form_finish_task->Show();
			 }
}
		 // обработка нажатия на кнопку выхода
private: System::Void exit_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 //delete my_system;
			 delete form_general_task, form_block_task, form_finish_task;
			 delete this;
}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 form_block_task->Show();
	}
private: System::Void finish_task_button_Click(System::Object^  sender, System::EventArgs^  e) {
				 form_finish_task->Show();
}
		 // блокировка выбранной задачи
private: System::Void dataGridView_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 if (e->ColumnIndex == 5)
			 {
				 my_system->block_task(e->RowIndex);
			 }
}
};
}
