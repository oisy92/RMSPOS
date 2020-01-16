#include "pch.h"
#include "Main.h"
#include "Admin.h"
#include "Waiter.h"
#include "Table.h"
#include "Drink.h"
#include "Entree.h"
#include "Mains.h"
#include "Dessert.h"

vector<Admin> Admin::adminsVector;
vector<Waiter> Waiter::waitersVector;
vector<Waiter> Waiter::clockedinWaiters;
vector<Table> Table::tablesVector;
using namespace System;

RMSPOS::Main::Main(void) {
  InitializeComponent();
  CurrentTimeTimer->Start();
}

void RMSPOS::Main::hideAll() {
  for (int i = 0; i <= Controls->Count - 1; i++) {
    std::string std_itemNamerichTextBox =
        marshal_as<std::string>(Controls->GetType()->ToString());
    if (Controls[i]->Name->Contains("footer") ||
        Controls[i]->Name->Contains("header") ||
        Controls[i]->Name->Contains("side")) {
      Controls[i]->Show();
    } else {
      Controls[i]->Hide();
    }
  }
}

String ^ RMSPOS::Main::getDate() {
  DateTime date = DateTime::Now;
  String ^ dateString = date.ToString("dd/mm/yyyy");
  return dateString;
}

String ^ RMSPOS::Main::getTime() {
  DateTime time = DateTime::Now;
  String ^ timeString = time.ToLongTimeString();
  return timeString;
}

void RMSPOS::Main::InitializeComponent(void) {
  this->components = (gcnew System::ComponentModel::Container());
  System::ComponentModel::ComponentResourceManager ^ resources =
      (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
  this->sidePanel = (gcnew System::Windows::Forms::Panel());
  this->tablesButton = (gcnew System::Windows::Forms::Button());
  this->adminButton = (gcnew System::Windows::Forms::Button());
  this->clockButton = (gcnew System::Windows::Forms::Button());
  this->dessertButton = (gcnew System::Windows::Forms::Button());
  this->mainButton = (gcnew System::Windows::Forms::Button());
  this->entreeButton = (gcnew System::Windows::Forms::Button());
  this->drinkButton = (gcnew System::Windows::Forms::Button());
  this->adminPanel = (gcnew System::Windows::Forms::Panel());
  this->contactPanel = (gcnew System::Windows::Forms::Panel());
  this->Contact = (gcnew System::Windows::Forms::PictureBox());
  this->orderSuppliesButton = (gcnew System::Windows::Forms::Button());
  this->removePanel = (gcnew System::Windows::Forms::Panel());
  this->button2 = (gcnew System::Windows::Forms::Button());
  this->removeManagerButton = (gcnew System::Windows::Forms::Button());
  this->removeWaiterButton = (gcnew System::Windows::Forms::Button());
  this->removeMenuItemButton = (gcnew System::Windows::Forms::Button());
  this->Remove = (gcnew System::Windows::Forms::PictureBox());
  this->addPanel = (gcnew System::Windows::Forms::Panel());
  this->addNewTableButton = (gcnew System::Windows::Forms::Button());
  this->addManagerButton = (gcnew System::Windows::Forms::Button());
  this->addWaiterButton = (gcnew System::Windows::Forms::Button());
  this->addMenuItemButton = (gcnew System::Windows::Forms::Button());
  this->Add = (gcnew System::Windows::Forms::PictureBox());
  this->footerPanel = (gcnew System::Windows::Forms::Panel());
  this->label1 = (gcnew System::Windows::Forms::Label());
  this->footerStaffValueLabel = (gcnew System::Windows::Forms::Label());
  this->footerDateValueLabel = (gcnew System::Windows::Forms::Label());
  this->footerTimeValueLabel = (gcnew System::Windows::Forms::Label());
  this->footerVacantTableslabel = (gcnew System::Windows::Forms::Label());
  this->footerStafflabel = (gcnew System::Windows::Forms::Label());
  this->footerDatelabel = (gcnew System::Windows::Forms::Label());
  this->footerTimeLabel = (gcnew System::Windows::Forms::Label());
  this->headerPanel = (gcnew System::Windows::Forms::Panel());
  this->headerLabel = (gcnew System::Windows::Forms::Label());
  this->clockinPanel = (gcnew System::Windows::Forms::Panel());
  this->clockinFailedLabel = (gcnew System::Windows::Forms::Label());
  this->staffpasswordrichTextBox =
      (gcnew System::Windows::Forms::RichTextBox());
  this->clockOutbutton = (gcnew System::Windows::Forms::Button());
  this->clockinButton = (gcnew System::Windows::Forms::Button());
  this->staffpasswordLabel = (gcnew System::Windows::Forms::Label());
  this->staffnumberLabel = (gcnew System::Windows::Forms::Label());
  this->staffnumberrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->adminLoginPanel = (gcnew System::Windows::Forms::Panel());
  this->loginFailedLabel = (gcnew System::Windows::Forms::Label());
  this->adminPasswordrichTextBox =
      (gcnew System::Windows::Forms::RichTextBox());
  this->LoginButton = (gcnew System::Windows::Forms::Button());
  this->adminPasswordLabel = (gcnew System::Windows::Forms::Label());
  this->adminNumberLabel = (gcnew System::Windows::Forms::Label());
  this->adminNumberrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->drinksMenuPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
  this->addItemPanel = (gcnew System::Windows::Forms::Panel());
  this->errorLabel = (gcnew System::Windows::Forms::Label());
  this->itemCategory = (gcnew System::Windows::Forms::ComboBox());
  this->addDrinkButton = (gcnew System::Windows::Forms::Button());
  this->itemPricerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->itemPriceLabel = (gcnew System::Windows::Forms::Label());
  this->itemNameLabel = (gcnew System::Windows::Forms::Label());
  this->itemNamerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->entreeMenuPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
  this->mainMenuPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
  this->dessertMenuPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
  this->newAdminPanel = (gcnew System::Windows::Forms::Panel());
  this->salaryLabel = (gcnew System::Windows::Forms::Label());
  this->employmentTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
  this->salaryrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->addressrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->agerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->genderrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->employmenttypeLabel = (gcnew System::Windows::Forms::Label());
  this->addressLabel = (gcnew System::Windows::Forms::Label());
  this->ageLabel = (gcnew System::Windows::Forms::Label());
  this->genderLabel = (gcnew System::Windows::Forms::Label());
  this->lastnamerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->createnewadminButton = (gcnew System::Windows::Forms::Button());
  this->lastnameLabel = (gcnew System::Windows::Forms::Label());
  this->firstnameLabel = (gcnew System::Windows::Forms::Label());
  this->firstnamerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->newWaiterPanel = (gcnew System::Windows::Forms::Panel());
  this->waiterSalaryLabel = (gcnew System::Windows::Forms::Label());
  this->WaiterEmploymentTypeComboBox =
      (gcnew System::Windows::Forms::ComboBox());
  this->waiterSalaryrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->waiterAddressrichTextBox =
      (gcnew System::Windows::Forms::RichTextBox());
  this->waiterAgerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->waiterGenderrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->waiterEmploymentTypeLabel = (gcnew System::Windows::Forms::Label());
  this->waiterAdressLabel = (gcnew System::Windows::Forms::Label());
  this->waiterAgeLabel = (gcnew System::Windows::Forms::Label());
  this->waiterGenderLabel = (gcnew System::Windows::Forms::Label());
  this->waiterLastNamerichTextBox =
      (gcnew System::Windows::Forms::RichTextBox());
  this->waiterCreateNewButton = (gcnew System::Windows::Forms::Button());
  this->waiterLastNameLabel = (gcnew System::Windows::Forms::Label());
  this->waiterFirstNameLabel = (gcnew System::Windows::Forms::Label());
  this->waiterFirstNamerichTextBox =
      (gcnew System::Windows::Forms::RichTextBox());
  this->CurrentTimeTimer =
      (gcnew System::Windows::Forms::Timer(this->components));
  this->tablesLayoutPanel = (gcnew System::Windows::Forms::Panel());
  this->newTablesPanel = (gcnew System::Windows::Forms::Panel());
  this->createNewTableButton = (gcnew System::Windows::Forms::Button());
  this->tablesSeatsLabel = (gcnew System::Windows::Forms::Label());
  this->tablesSeatsrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
  this->sidePanel->SuspendLayout();
  this->adminPanel->SuspendLayout();
  this->contactPanel->SuspendLayout();
  (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Contact))
      ->BeginInit();
  this->removePanel->SuspendLayout();
  (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Remove))
      ->BeginInit();
  this->addPanel->SuspendLayout();
  (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Add))
      ->BeginInit();
  this->footerPanel->SuspendLayout();
  this->headerPanel->SuspendLayout();
  this->clockinPanel->SuspendLayout();
  this->adminLoginPanel->SuspendLayout();
  this->addItemPanel->SuspendLayout();
  this->newAdminPanel->SuspendLayout();
  this->newWaiterPanel->SuspendLayout();
  this->newTablesPanel->SuspendLayout();
  this->SuspendLayout();
  //
  // sidePanel
  //
  this->sidePanel->AutoSize = true;
  this->sidePanel->BackColor = System::Drawing::Color::MidnightBlue;
  this->sidePanel->Controls->Add(this->tablesButton);
  this->sidePanel->Controls->Add(this->adminButton);
  this->sidePanel->Controls->Add(this->clockButton);
  this->sidePanel->Controls->Add(this->dessertButton);
  this->sidePanel->Controls->Add(this->mainButton);
  this->sidePanel->Controls->Add(this->entreeButton);
  this->sidePanel->Controls->Add(this->drinkButton);
  this->sidePanel->Dock = System::Windows::Forms::DockStyle::Left;
  this->sidePanel->Location = System::Drawing::Point(0, 0);
  this->sidePanel->Name = L"sidePanel";
  this->sidePanel->Size = System::Drawing::Size(80, 782);
  this->sidePanel->TabIndex = 0;
  //
  // tablesButton
  //
  this->tablesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->tablesButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"tablesButton.Image")));
  this->tablesButton->Location = System::Drawing::Point(0, 86);
  this->tablesButton->Name = L"tablesButton";
  this->tablesButton->Size = System::Drawing::Size(77, 81);
  this->tablesButton->TabIndex = 6;
  this->tablesButton->UseVisualStyleBackColor = true;
  this->tablesButton->Click +=
      gcnew System::EventHandler(this, &Main::tablesButton_Click);
  //
  // adminButton
  //
  this->adminButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
      (System::Windows::Forms::AnchorStyles::Bottom |
       System::Windows::Forms::AnchorStyles::Left));
  this->adminButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->adminButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"adminButton.Image")));
  this->adminButton->Location = System::Drawing::Point(0, 630);
  this->adminButton->Name = L"adminButton";
  this->adminButton->Size = System::Drawing::Size(77, 67);
  this->adminButton->TabIndex = 5;
  this->adminButton->UseVisualStyleBackColor = true;
  this->adminButton->Click +=
      gcnew System::EventHandler(this, &Main::adminButton_Click);
  //
  // clockButton
  //
  this->clockButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
      (System::Windows::Forms::AnchorStyles::Bottom |
       System::Windows::Forms::AnchorStyles::Left));
  this->clockButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->clockButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"clockButton.Image")));
  this->clockButton->Location = System::Drawing::Point(0, 557);
  this->clockButton->Name = L"clockButton";
  this->clockButton->Size = System::Drawing::Size(77, 67);
  this->clockButton->TabIndex = 4;
  this->clockButton->UseVisualStyleBackColor = true;
  this->clockButton->Click +=
      gcnew System::EventHandler(this, &Main::clockButton_Click);
  //
  // dessertButton
  //
  this->dessertButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->dessertButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"dessertButton.Image")));
  this->dessertButton->Location = System::Drawing::Point(0, 399);
  this->dessertButton->Name = L"dessertButton";
  this->dessertButton->Size = System::Drawing::Size(77, 67);
  this->dessertButton->TabIndex = 3;
  this->dessertButton->UseVisualStyleBackColor = true;
  this->dessertButton->Click +=
      gcnew System::EventHandler(this, &Main::dessertButton_Click);
  //
  // mainButton
  //
  this->mainButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->mainButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"mainButton.Image")));
  this->mainButton->Location = System::Drawing::Point(0, 326);
  this->mainButton->Name = L"mainButton";
  this->mainButton->Size = System::Drawing::Size(77, 67);
  this->mainButton->TabIndex = 2;
  this->mainButton->UseVisualStyleBackColor = true;
  this->mainButton->Click +=
      gcnew System::EventHandler(this, &Main::mainButton_Click);
  //
  // entreeButton
  //
  this->entreeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->entreeButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"entreeButton.Image")));
  this->entreeButton->Location = System::Drawing::Point(0, 253);
  this->entreeButton->Name = L"entreeButton";
  this->entreeButton->Size = System::Drawing::Size(77, 67);
  this->entreeButton->TabIndex = 1;
  this->entreeButton->UseVisualStyleBackColor = true;
  this->entreeButton->Click +=
      gcnew System::EventHandler(this, &Main::entreeButton_Click);
  //
  // drinkButton
  //
  this->drinkButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->drinkButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"drinkButton.Image")));
  this->drinkButton->Location = System::Drawing::Point(0, 166);
  this->drinkButton->Name = L"drinkButton";
  this->drinkButton->Size = System::Drawing::Size(77, 81);
  this->drinkButton->TabIndex = 0;
  this->drinkButton->UseVisualStyleBackColor = true;
  this->drinkButton->Click +=
      gcnew System::EventHandler(this, &Main::drinkButton_Click);
  //
  // adminPanel
  //
  this->adminPanel->Controls->Add(this->contactPanel);
  this->adminPanel->Controls->Add(this->removePanel);
  this->adminPanel->Controls->Add(this->addPanel);
  this->adminPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->adminPanel->Location = System::Drawing::Point(80, 84);
  this->adminPanel->Name = L"adminPanel";
  this->adminPanel->Size = System::Drawing::Size(1220, 614);
  this->adminPanel->TabIndex = 13;
  this->adminPanel->Visible = false;
  //
  // contactPanel
  //
  this->contactPanel->BackColor = System::Drawing::SystemColors::ControlLight;
  this->contactPanel->BorderStyle =
      System::Windows::Forms::BorderStyle::FixedSingle;
  this->contactPanel->Controls->Add(this->Contact);
  this->contactPanel->Controls->Add(this->orderSuppliesButton);
  this->contactPanel->Dock = System::Windows::Forms::DockStyle::Left;
  this->contactPanel->Location = System::Drawing::Point(514, 0);
  this->contactPanel->Name = L"contactPanel";
  this->contactPanel->Size = System::Drawing::Size(257, 614);
  this->contactPanel->TabIndex = 10;
  //
  // Contact
  //
  this->Contact->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"Contact.Image")));
  this->Contact->Location = System::Drawing::Point(66, 0);
  this->Contact->Name = L"Contact";
  this->Contact->Size = System::Drawing::Size(128, 128);
  this->Contact->SizeMode =
      System::Windows::Forms::PictureBoxSizeMode::AutoSize;
  this->Contact->TabIndex = 3;
  this->Contact->TabStop = false;
  //
  // orderSuppliesButton
  //
  this->orderSuppliesButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"orderSuppliesButton.Image")));
  this->orderSuppliesButton->Location = System::Drawing::Point(18, 191);
  this->orderSuppliesButton->Name = L"orderSuppliesButton";
  this->orderSuppliesButton->Size = System::Drawing::Size(77, 81);
  this->orderSuppliesButton->TabIndex = 1;
  this->orderSuppliesButton->UseVisualStyleBackColor = true;
  //
  // removePanel
  //
  this->removePanel->BackColor = System::Drawing::SystemColors::ControlLight;
  this->removePanel->BorderStyle =
      System::Windows::Forms::BorderStyle::FixedSingle;
  this->removePanel->Controls->Add(this->button2);
  this->removePanel->Controls->Add(this->removeManagerButton);
  this->removePanel->Controls->Add(this->removeWaiterButton);
  this->removePanel->Controls->Add(this->removeMenuItemButton);
  this->removePanel->Controls->Add(this->Remove);
  this->removePanel->Dock = System::Windows::Forms::DockStyle::Left;
  this->removePanel->Location = System::Drawing::Point(257, 0);
  this->removePanel->Name = L"removePanel";
  this->removePanel->Size = System::Drawing::Size(257, 614);
  this->removePanel->TabIndex = 9;
  //
  // button2
  //
  this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->button2->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"button2.Image")));
  this->button2->Location = System::Drawing::Point(15, 191);
  this->button2->Name = L"button2";
  this->button2->Size = System::Drawing::Size(77, 81);
  this->button2->TabIndex = 12;
  this->button2->UseVisualStyleBackColor = true;
  //
  // removeManagerButton
  //
  this->removeManagerButton->FlatStyle =
      System::Windows::Forms::FlatStyle::Flat;
  this->removeManagerButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"removeManagerButton.Image")));
  this->removeManagerButton->Location = System::Drawing::Point(15, 280);
  this->removeManagerButton->Name = L"removeManagerButton";
  this->removeManagerButton->Size = System::Drawing::Size(77, 81);
  this->removeManagerButton->TabIndex = 11;
  this->removeManagerButton->UseVisualStyleBackColor = true;
  //
  // removeWaiterButton
  //
  this->removeWaiterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->removeWaiterButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"removeWaiterButton.Image")));
  this->removeWaiterButton->Location = System::Drawing::Point(141, 280);
  this->removeWaiterButton->Name = L"removeWaiterButton";
  this->removeWaiterButton->Size = System::Drawing::Size(77, 81);
  this->removeWaiterButton->TabIndex = 10;
  this->removeWaiterButton->UseVisualStyleBackColor = true;
  //
  // removeMenuItemButton
  //
  this->removeMenuItemButton->FlatStyle =
      System::Windows::Forms::FlatStyle::Flat;
  this->removeMenuItemButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"removeMenuItemButton.Image")));
  this->removeMenuItemButton->Location = System::Drawing::Point(141, 191);
  this->removeMenuItemButton->Name = L"removeMenuItemButton";
  this->removeMenuItemButton->Size = System::Drawing::Size(77, 81);
  this->removeMenuItemButton->TabIndex = 9;
  this->removeMenuItemButton->UseVisualStyleBackColor = true;
  //
  // Remove
  //
  this->Remove->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"Remove.Image")));
  this->Remove->Location = System::Drawing::Point(66, 0);
  this->Remove->Name = L"Remove";
  this->Remove->Size = System::Drawing::Size(128, 128);
  this->Remove->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
  this->Remove->TabIndex = 3;
  this->Remove->TabStop = false;
  //
  // addPanel
  //
  this->addPanel->BackColor = System::Drawing::SystemColors::ControlLight;
  this->addPanel->BorderStyle =
      System::Windows::Forms::BorderStyle::FixedSingle;
  this->addPanel->Controls->Add(this->addNewTableButton);
  this->addPanel->Controls->Add(this->addManagerButton);
  this->addPanel->Controls->Add(this->addWaiterButton);
  this->addPanel->Controls->Add(this->addMenuItemButton);
  this->addPanel->Controls->Add(this->Add);
  this->addPanel->Dock = System::Windows::Forms::DockStyle::Left;
  this->addPanel->Location = System::Drawing::Point(0, 0);
  this->addPanel->Name = L"addPanel";
  this->addPanel->Size = System::Drawing::Size(257, 614);
  this->addPanel->TabIndex = 8;
  //
  // addNewTableButton
  //
  this->addNewTableButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->addNewTableButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"addNewTableButton.Image")));
  this->addNewTableButton->Location = System::Drawing::Point(22, 191);
  this->addNewTableButton->Name = L"addNewTableButton";
  this->addNewTableButton->Size = System::Drawing::Size(77, 81);
  this->addNewTableButton->TabIndex = 10;
  this->addNewTableButton->UseVisualStyleBackColor = true;
  this->addNewTableButton->Click +=
      gcnew System::EventHandler(this, &Main::addNewTableButton_Click);
  //
  // addManagerButton
  //
  this->addManagerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->addManagerButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"addManagerButton.Image")));
  this->addManagerButton->Location = System::Drawing::Point(22, 280);
  this->addManagerButton->Name = L"addManagerButton";
  this->addManagerButton->Size = System::Drawing::Size(77, 81);
  this->addManagerButton->TabIndex = 9;
  this->addManagerButton->UseVisualStyleBackColor = true;
  this->addManagerButton->Click +=
      gcnew System::EventHandler(this, &Main::addManagerButton_Click);
  //
  // addWaiterButton
  //
  this->addWaiterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->addWaiterButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"addWaiterButton.Image")));
  this->addWaiterButton->Location = System::Drawing::Point(146, 285);
  this->addWaiterButton->Name = L"addWaiterButton";
  this->addWaiterButton->Size = System::Drawing::Size(77, 81);
  this->addWaiterButton->TabIndex = 8;
  this->addWaiterButton->UseVisualStyleBackColor = true;
  this->addWaiterButton->Click +=
      gcnew System::EventHandler(this, &Main::addWaiterButton_Click);
  //
  // addMenuItemButton
  //
  this->addMenuItemButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
  this->addMenuItemButton->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"addMenuItemButton.Image")));
  this->addMenuItemButton->Location = System::Drawing::Point(146, 191);
  this->addMenuItemButton->Name = L"addMenuItemButton";
  this->addMenuItemButton->Size = System::Drawing::Size(77, 81);
  this->addMenuItemButton->TabIndex = 7;
  this->addMenuItemButton->UseVisualStyleBackColor = true;
  this->addMenuItemButton->Click +=
      gcnew System::EventHandler(this, &Main::addMenuItemButton_Click);
  //
  // Add
  //
  this->Add->Image = (cli::safe_cast<System::Drawing::Image ^>(
      resources->GetObject(L"Add.Image")));
  this->Add->Location = System::Drawing::Point(66, 0);
  this->Add->Name = L"Add";
  this->Add->Size = System::Drawing::Size(128, 128);
  this->Add->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
  this->Add->TabIndex = 3;
  this->Add->TabStop = false;
  //
  // footerPanel
  //
  this->footerPanel->BackColor = System::Drawing::Color::MidnightBlue;
  this->footerPanel->Controls->Add(this->label1);
  this->footerPanel->Controls->Add(this->footerStaffValueLabel);
  this->footerPanel->Controls->Add(this->footerDateValueLabel);
  this->footerPanel->Controls->Add(this->footerTimeValueLabel);
  this->footerPanel->Controls->Add(this->footerVacantTableslabel);
  this->footerPanel->Controls->Add(this->footerStafflabel);
  this->footerPanel->Controls->Add(this->footerDatelabel);
  this->footerPanel->Controls->Add(this->footerTimeLabel);
  this->footerPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
  this->footerPanel->Location = System::Drawing::Point(80, 698);
  this->footerPanel->Name = L"footerPanel";
  this->footerPanel->Size = System::Drawing::Size(1220, 84);
  this->footerPanel->TabIndex = 1;
  //
  // label1
  //
  this->label1->AutoSize = true;
  this->label1->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->label1->ForeColor = System::Drawing::SystemColors::ControlLight;
  this->label1->Location = System::Drawing::Point(534, 50);
  this->label1->Name = L"label1";
  this->label1->Size = System::Drawing::Size(58, 25);
  this->label1->TabIndex = 9;
  this->label1->Text = L"NULL";
  //
  // footerStaffValueLabel
  //
  this->footerStaffValueLabel->AutoSize = true;
  this->footerStaffValueLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->footerStaffValueLabel->ForeColor =
      System::Drawing::SystemColors::ControlLight;
  this->footerStaffValueLabel->Location = System::Drawing::Point(456, 3);
  this->footerStaffValueLabel->Name = L"footerStaffValueLabel";
  this->footerStaffValueLabel->Size = System::Drawing::Size(58, 25);
  this->footerStaffValueLabel->TabIndex = 8;
  this->footerStaffValueLabel->Text = L"NULL";
  //
  // footerDateValueLabel
  //
  this->footerDateValueLabel->AutoSize = true;
  this->footerDateValueLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->footerDateValueLabel->ForeColor =
      System::Drawing::SystemColors::ControlLight;
  this->footerDateValueLabel->Location = System::Drawing::Point(65, 50);
  this->footerDateValueLabel->Name = L"footerDateValueLabel";
  this->footerDateValueLabel->Size = System::Drawing::Size(58, 25);
  this->footerDateValueLabel->TabIndex = 7;
  this->footerDateValueLabel->Text = L"NULL";
  //
  // footerTimeValueLabel
  //
  this->footerTimeValueLabel->AutoSize = true;
  this->footerTimeValueLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->footerTimeValueLabel->ForeColor =
      System::Drawing::SystemColors::ControlLight;
  this->footerTimeValueLabel->Location = System::Drawing::Point(65, 3);
  this->footerTimeValueLabel->Name = L"footerTimeValueLabel";
  this->footerTimeValueLabel->Size = System::Drawing::Size(58, 25);
  this->footerTimeValueLabel->TabIndex = 6;
  this->footerTimeValueLabel->Text = L"NULL";
  //
  // footerVacantTableslabel
  //
  this->footerVacantTableslabel->Anchor =
      static_cast<System::Windows::Forms::AnchorStyles>(
          (((System::Windows::Forms::AnchorStyles::Top |
             System::Windows::Forms::AnchorStyles::Bottom) |
            System::Windows::Forms::AnchorStyles::Left) |
           System::Windows::Forms::AnchorStyles::Right));
  this->footerVacantTableslabel->AutoSize = true;
  this->footerVacantTableslabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->footerVacantTableslabel->ForeColor =
      System::Drawing::SystemColors::ControlLight;
  this->footerVacantTableslabel->Location = System::Drawing::Point(395, 50);
  this->footerVacantTableslabel->Name = L"footerVacantTableslabel";
  this->footerVacantTableslabel->Size = System::Drawing::Size(138, 25);
  this->footerVacantTableslabel->TabIndex = 4;
  this->footerVacantTableslabel->Text = L"Vacant Tables:";
  //
  // footerStafflabel
  //
  this->footerStafflabel->Anchor =
      static_cast<System::Windows::Forms::AnchorStyles>(
          (((System::Windows::Forms::AnchorStyles::Top |
             System::Windows::Forms::AnchorStyles::Bottom) |
            System::Windows::Forms::AnchorStyles::Left) |
           System::Windows::Forms::AnchorStyles::Right));
  this->footerStafflabel->AutoSize = true;
  this->footerStafflabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->footerStafflabel->ForeColor =
      System::Drawing::SystemColors::ControlLight;
  this->footerStafflabel->Location = System::Drawing::Point(395, 3);
  this->footerStafflabel->Name = L"footerStafflabel";
  this->footerStafflabel->Size = System::Drawing::Size(57, 25);
  this->footerStafflabel->TabIndex = 2;
  this->footerStafflabel->Text = L"Staff:";
  //
  // footerDatelabel
  //
  this->footerDatelabel->AutoSize = true;
  this->footerDatelabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->footerDatelabel->ForeColor =
      System::Drawing::SystemColors::ControlLight;
  this->footerDatelabel->Location = System::Drawing::Point(9, 50);
  this->footerDatelabel->Name = L"footerDatelabel";
  this->footerDatelabel->Size = System::Drawing::Size(56, 25);
  this->footerDatelabel->TabIndex = 1;
  this->footerDatelabel->Text = L"Date:";
  //
  // footerTimeLabel
  //
  this->footerTimeLabel->AutoSize = true;
  this->footerTimeLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->footerTimeLabel->ForeColor =
      System::Drawing::SystemColors::ControlLight;
  this->footerTimeLabel->Location = System::Drawing::Point(6, 3);
  this->footerTimeLabel->Name = L"footerTimeLabel";
  this->footerTimeLabel->Size = System::Drawing::Size(59, 25);
  this->footerTimeLabel->TabIndex = 0;
  this->footerTimeLabel->Text = L"Time:";
  //
  // headerPanel
  //
  this->headerPanel->BackColor = System::Drawing::Color::MidnightBlue;
  this->headerPanel->Controls->Add(this->headerLabel);
  this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
  this->headerPanel->Location = System::Drawing::Point(80, 0);
  this->headerPanel->Name = L"headerPanel";
  this->headerPanel->Size = System::Drawing::Size(1220, 84);
  this->headerPanel->TabIndex = 2;
  //
  // headerLabel
  //
  this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
      (((System::Windows::Forms::AnchorStyles::Top |
         System::Windows::Forms::AnchorStyles::Bottom) |
        System::Windows::Forms::AnchorStyles::Left) |
       System::Windows::Forms::AnchorStyles::Right));
  this->headerLabel->AutoSize = true;
  this->headerLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 48, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->headerLabel->ForeColor = System::Drawing::SystemColors::ControlLight;
  this->headerLabel->Location = System::Drawing::Point(375, 6);
  this->headerLabel->Name = L"headerLabel";
  this->headerLabel->Size = System::Drawing::Size(260, 75);
  this->headerLabel->TabIndex = 0;
  this->headerLabel->Text = L"RMSPOS";
  //
  // clockinPanel
  //
  this->clockinPanel->Controls->Add(this->clockinFailedLabel);
  this->clockinPanel->Controls->Add(this->staffpasswordrichTextBox);
  this->clockinPanel->Controls->Add(this->clockOutbutton);
  this->clockinPanel->Controls->Add(this->clockinButton);
  this->clockinPanel->Controls->Add(this->staffpasswordLabel);
  this->clockinPanel->Controls->Add(this->staffnumberLabel);
  this->clockinPanel->Controls->Add(this->staffnumberrichTextBox);
  this->clockinPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->clockinPanel->Location = System::Drawing::Point(80, 84);
  this->clockinPanel->Name = L"clockinPanel";
  this->clockinPanel->Size = System::Drawing::Size(1220, 614);
  this->clockinPanel->TabIndex = 3;
  this->clockinPanel->Visible = false;
  //
  // clockinFailedLabel
  //
  this->clockinFailedLabel->AutoSize = true;
  this->clockinFailedLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->clockinFailedLabel->ForeColor = System::Drawing::Color::Red;
  this->clockinFailedLabel->Location = System::Drawing::Point(309, 460);
  this->clockinFailedLabel->Name = L"clockinFailedLabel";
  this->clockinFailedLabel->Size = System::Drawing::Size(315, 37);
  this->clockinFailedLabel->TabIndex = 7;
  this->clockinFailedLabel->Text = L"Initials or ID is incorrect";
  this->clockinFailedLabel->Visible = false;
  //
  // staffpasswordrichTextBox
  //
  this->staffpasswordrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->staffpasswordrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->staffpasswordrichTextBox->Location = System::Drawing::Point(381, 240);
  this->staffpasswordrichTextBox->MaxLength = 10;
  this->staffpasswordrichTextBox->Name = L"staffpasswordrichTextBox";
  this->staffpasswordrichTextBox->Size = System::Drawing::Size(180, 48);
  this->staffpasswordrichTextBox->TabIndex = 6;
  this->staffpasswordrichTextBox->Text = L"";
  //
  // clockOutbutton
  //
  this->clockOutbutton->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->clockOutbutton->ForeColor = System::Drawing::Color::Crimson;
  this->clockOutbutton->Location = System::Drawing::Point(399, 363);
  this->clockOutbutton->Name = L"clockOutbutton";
  this->clockOutbutton->Size = System::Drawing::Size(151, 45);
  this->clockOutbutton->TabIndex = 5;
  this->clockOutbutton->Text = L"Clock out";
  this->clockOutbutton->UseVisualStyleBackColor = true;
  //
  // clockinButton
  //
  this->clockinButton->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->clockinButton->ForeColor = System::Drawing::Color::DodgerBlue;
  this->clockinButton->Location = System::Drawing::Point(399, 303);
  this->clockinButton->Name = L"clockinButton";
  this->clockinButton->Size = System::Drawing::Size(151, 45);
  this->clockinButton->TabIndex = 4;
  this->clockinButton->Text = L"Clock in";
  this->clockinButton->UseVisualStyleBackColor = true;
  this->clockinButton->Click +=
      gcnew System::EventHandler(this, &Main::clockinButton_Click);
  //
  // staffpasswordLabel
  //
  this->staffpasswordLabel->AutoSize = true;
  this->staffpasswordLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->staffpasswordLabel->Location = System::Drawing::Point(409, 200);
  this->staffpasswordLabel->Name = L"staffpasswordLabel";
  this->staffpasswordLabel->Size = System::Drawing::Size(110, 37);
  this->staffpasswordLabel->TabIndex = 1;
  this->staffpasswordLabel->Text = L"Staff ID";
  //
  // staffnumberLabel
  //
  this->staffnumberLabel->AutoSize = true;
  this->staffnumberLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->staffnumberLabel->Location = System::Drawing::Point(381, 97);
  this->staffnumberLabel->Name = L"staffnumberLabel";
  this->staffnumberLabel->Size = System::Drawing::Size(167, 37);
  this->staffnumberLabel->TabIndex = 0;
  this->staffnumberLabel->Text = L"Staff Initials";
  //
  // staffnumberrichTextBox
  //
  this->staffnumberrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->staffnumberrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->staffnumberrichTextBox->Location = System::Drawing::Point(381, 149);
  this->staffnumberrichTextBox->MaxLength = 10;
  this->staffnumberrichTextBox->Name = L"staffnumberrichTextBox";
  this->staffnumberrichTextBox->Size = System::Drawing::Size(180, 48);
  this->staffnumberrichTextBox->TabIndex = 2;
  this->staffnumberrichTextBox->Text = L"";
  //
  // adminLoginPanel
  //
  this->adminLoginPanel->Controls->Add(this->loginFailedLabel);
  this->adminLoginPanel->Controls->Add(this->adminPasswordrichTextBox);
  this->adminLoginPanel->Controls->Add(this->LoginButton);
  this->adminLoginPanel->Controls->Add(this->adminPasswordLabel);
  this->adminLoginPanel->Controls->Add(this->adminNumberLabel);
  this->adminLoginPanel->Controls->Add(this->adminNumberrichTextBox);
  this->adminLoginPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->adminLoginPanel->Location = System::Drawing::Point(80, 84);
  this->adminLoginPanel->Name = L"adminLoginPanel";
  this->adminLoginPanel->Size = System::Drawing::Size(1220, 614);
  this->adminLoginPanel->TabIndex = 7;
  this->adminLoginPanel->Visible = false;
  //
  // loginFailedLabel
  //
  this->loginFailedLabel->AutoSize = true;
  this->loginFailedLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->loginFailedLabel->ForeColor = System::Drawing::Color::Red;
  this->loginFailedLabel->Location = System::Drawing::Point(281, 395);
  this->loginFailedLabel->Name = L"loginFailedLabel";
  this->loginFailedLabel->Size = System::Drawing::Size(457, 37);
  this->loginFailedLabel->TabIndex = 13;
  this->loginFailedLabel->Text = L"Username or password is incorrect";
  this->loginFailedLabel->Visible = false;
  //
  // adminPasswordrichTextBox
  //
  this->adminPasswordrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->adminPasswordrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->adminPasswordrichTextBox->Location = System::Drawing::Point(423, 262);
  this->adminPasswordrichTextBox->MaxLength = 10;
  this->adminPasswordrichTextBox->Name = L"adminPasswordrichTextBox";
  this->adminPasswordrichTextBox->Size = System::Drawing::Size(180, 48);
  this->adminPasswordrichTextBox->TabIndex = 12;
  this->adminPasswordrichTextBox->Text = L"";
  //
  // LoginButton
  //
  this->LoginButton->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->LoginButton->ForeColor = System::Drawing::Color::DodgerBlue;
  this->LoginButton->Location = System::Drawing::Point(441, 325);
  this->LoginButton->Name = L"LoginButton";
  this->LoginButton->Size = System::Drawing::Size(151, 45);
  this->LoginButton->TabIndex = 10;
  this->LoginButton->Text = L"Log in";
  this->LoginButton->UseVisualStyleBackColor = true;
  this->LoginButton->Click +=
      gcnew System::EventHandler(this, &Main::LoginButton_Click);
  //
  // adminPasswordLabel
  //
  this->adminPasswordLabel->AutoSize = true;
  this->adminPasswordLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->adminPasswordLabel->Location = System::Drawing::Point(416, 222);
  this->adminPasswordLabel->Name = L"adminPasswordLabel";
  this->adminPasswordLabel->Size = System::Drawing::Size(230, 37);
  this->adminPasswordLabel->TabIndex = 8;
  this->adminPasswordLabel->Text = L"Admin Password";
  //
  // adminNumberLabel
  //
  this->adminNumberLabel->AutoSize = true;
  this->adminNumberLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->adminNumberLabel->Location = System::Drawing::Point(423, 119);
  this->adminNumberLabel->Name = L"adminNumberLabel";
  this->adminNumberLabel->Size = System::Drawing::Size(201, 37);
  this->adminNumberLabel->TabIndex = 7;
  this->adminNumberLabel->Text = L"Admin number";
  //
  // adminNumberrichTextBox
  //
  this->adminNumberrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->adminNumberrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->adminNumberrichTextBox->Location = System::Drawing::Point(423, 171);
  this->adminNumberrichTextBox->MaxLength = 10;
  this->adminNumberrichTextBox->Name = L"adminNumberrichTextBox";
  this->adminNumberrichTextBox->Size = System::Drawing::Size(180, 48);
  this->adminNumberrichTextBox->TabIndex = 9;
  this->adminNumberrichTextBox->Text = L"";
  //
  // drinksMenuPanel
  //
  this->drinksMenuPanel->ColumnCount = 9;
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->drinksMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 604)));
  this->drinksMenuPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->drinksMenuPanel->Location = System::Drawing::Point(80, 84);
  this->drinksMenuPanel->Name = L"drinksMenuPanel";
  this->drinksMenuPanel->RowCount = 9;
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->drinksMenuPanel->Size = System::Drawing::Size(1220, 614);
  this->drinksMenuPanel->TabIndex = 3;
  this->drinksMenuPanel->Visible = false;
  //
  // addItemPanel
  //
  this->addItemPanel->Controls->Add(this->errorLabel);
  this->addItemPanel->Controls->Add(this->itemCategory);
  this->addItemPanel->Controls->Add(this->addDrinkButton);
  this->addItemPanel->Controls->Add(this->itemPricerichTextBox);
  this->addItemPanel->Controls->Add(this->itemPriceLabel);
  this->addItemPanel->Controls->Add(this->itemNameLabel);
  this->addItemPanel->Controls->Add(this->itemNamerichTextBox);
  this->addItemPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->addItemPanel->Location = System::Drawing::Point(80, 84);
  this->addItemPanel->Name = L"addItemPanel";
  this->addItemPanel->Size = System::Drawing::Size(1220, 614);
  this->addItemPanel->TabIndex = 8;
  this->addItemPanel->Visible = false;
  //
  // errorLabel
  //
  this->errorLabel->AutoSize = true;
  this->errorLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->errorLabel->ForeColor = System::Drawing::Color::Red;
  this->errorLabel->Location = System::Drawing::Point(256, 497);
  this->errorLabel->Name = L"errorLabel";
  this->errorLabel->Size = System::Drawing::Size(515, 25);
  this->errorLabel->TabIndex = 21;
  this->errorLabel->Text =
      L"Please first choose item category from the dropdown menu";
  this->errorLabel->Visible = false;
  //
  // itemCategory
  //
  this->itemCategory->DropDownStyle =
      System::Windows::Forms::ComboBoxStyle::DropDownList;
  this->itemCategory->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->itemCategory->FormattingEnabled = true;
  this->itemCategory->Items->AddRange(gcnew cli::array<System::Object ^>(4){
      L"Drink", L"Entree", L"Main", L"Dessert"});
  this->itemCategory->Location = System::Drawing::Point(423, 420);
  this->itemCategory->Name = L"itemCategory";
  this->itemCategory->Size = System::Drawing::Size(180, 45);
  this->itemCategory->TabIndex = 20;
  //
  // addDrinkButton
  //
  this->addDrinkButton->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->addDrinkButton->ForeColor = System::Drawing::Color::DodgerBlue;
  this->addDrinkButton->Location = System::Drawing::Point(423, 554);
  this->addDrinkButton->Name = L"addDrinkButton";
  this->addDrinkButton->Size = System::Drawing::Size(180, 45);
  this->addDrinkButton->TabIndex = 19;
  this->addDrinkButton->Text = L"Add";
  this->addDrinkButton->UseVisualStyleBackColor = true;
  this->addDrinkButton->Click +=
      gcnew System::EventHandler(this, &Main::addDrinkButton_Click);
  //
  // itemPricerichTextBox
  //
  this->itemPricerichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->itemPricerichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->itemPricerichTextBox->Location = System::Drawing::Point(423, 356);
  this->itemPricerichTextBox->MaxLength = 10;
  this->itemPricerichTextBox->Name = L"itemPricerichTextBox";
  this->itemPricerichTextBox->Size = System::Drawing::Size(180, 48);
  this->itemPricerichTextBox->TabIndex = 17;
  this->itemPricerichTextBox->Text = L"";
  //
  // itemPriceLabel
  //
  this->itemPriceLabel->AutoSize = true;
  this->itemPriceLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->itemPriceLabel->Location = System::Drawing::Point(435, 316);
  this->itemPriceLabel->Name = L"itemPriceLabel";
  this->itemPriceLabel->Size = System::Drawing::Size(143, 37);
  this->itemPriceLabel->TabIndex = 14;
  this->itemPriceLabel->Text = L"Item Price";
  //
  // itemNameLabel
  //
  this->itemNameLabel->AutoSize = true;
  this->itemNameLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->itemNameLabel->Location = System::Drawing::Point(432, 213);
  this->itemNameLabel->Name = L"itemNameLabel";
  this->itemNameLabel->Size = System::Drawing::Size(150, 37);
  this->itemNameLabel->TabIndex = 13;
  this->itemNameLabel->Text = L"Item Name";
  //
  // itemNamerichTextBox
  //
  this->itemNamerichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->itemNamerichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->itemNamerichTextBox->Location = System::Drawing::Point(423, 265);
  this->itemNamerichTextBox->MaxLength = 10;
  this->itemNamerichTextBox->Name = L"itemNamerichTextBox";
  this->itemNamerichTextBox->Size = System::Drawing::Size(180, 48);
  this->itemNamerichTextBox->TabIndex = 15;
  this->itemNamerichTextBox->Text = L"";
  //
  // entreeMenuPanel
  //
  this->entreeMenuPanel->ColumnCount = 9;
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->entreeMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 604)));
  this->entreeMenuPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->entreeMenuPanel->Location = System::Drawing::Point(80, 84);
  this->entreeMenuPanel->Name = L"entreeMenuPanel";
  this->entreeMenuPanel->RowCount = 9;
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->entreeMenuPanel->Size = System::Drawing::Size(1220, 614);
  this->entreeMenuPanel->TabIndex = 4;
  this->entreeMenuPanel->Visible = false;
  //
  // mainMenuPanel
  //
  this->mainMenuPanel->ColumnCount = 9;
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->mainMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 604)));
  this->mainMenuPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->mainMenuPanel->Location = System::Drawing::Point(80, 84);
  this->mainMenuPanel->Name = L"mainMenuPanel";
  this->mainMenuPanel->RowCount = 9;
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(
      System::Windows::Forms::SizeType::Absolute, 81)));
  this->mainMenuPanel->Size = System::Drawing::Size(1220, 614);
  this->mainMenuPanel->TabIndex = 5;
  this->mainMenuPanel->Visible = false;
  //
  // dessertMenuPanel
  //
  this->dessertMenuPanel->ColumnCount = 9;
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 77)));
  this->dessertMenuPanel->ColumnStyles->Add(
      (gcnew System::Windows::Forms::ColumnStyle(
          System::Windows::Forms::SizeType::Absolute, 604)));
  this->dessertMenuPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->dessertMenuPanel->Location = System::Drawing::Point(80, 84);
  this->dessertMenuPanel->Name = L"dessertMenuPanel";
  this->dessertMenuPanel->RowCount = 9;
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->RowStyles->Add(
      (gcnew System::Windows::Forms::RowStyle(
          System::Windows::Forms::SizeType::Absolute, 81)));
  this->dessertMenuPanel->Size = System::Drawing::Size(1220, 614);
  this->dessertMenuPanel->TabIndex = 5;
  this->dessertMenuPanel->Visible = false;
  //
  // newAdminPanel
  //
  this->newAdminPanel->Controls->Add(this->salaryLabel);
  this->newAdminPanel->Controls->Add(this->employmentTypeComboBox);
  this->newAdminPanel->Controls->Add(this->salaryrichTextBox);
  this->newAdminPanel->Controls->Add(this->addressrichTextBox);
  this->newAdminPanel->Controls->Add(this->agerichTextBox);
  this->newAdminPanel->Controls->Add(this->genderrichTextBox);
  this->newAdminPanel->Controls->Add(this->employmenttypeLabel);
  this->newAdminPanel->Controls->Add(this->addressLabel);
  this->newAdminPanel->Controls->Add(this->ageLabel);
  this->newAdminPanel->Controls->Add(this->genderLabel);
  this->newAdminPanel->Controls->Add(this->lastnamerichTextBox);
  this->newAdminPanel->Controls->Add(this->createnewadminButton);
  this->newAdminPanel->Controls->Add(this->lastnameLabel);
  this->newAdminPanel->Controls->Add(this->firstnameLabel);
  this->newAdminPanel->Controls->Add(this->firstnamerichTextBox);
  this->newAdminPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->newAdminPanel->Location = System::Drawing::Point(80, 84);
  this->newAdminPanel->Name = L"newAdminPanel";
  this->newAdminPanel->Size = System::Drawing::Size(1220, 614);
  this->newAdminPanel->TabIndex = 13;
  this->newAdminPanel->Visible = false;
  //
  // salaryLabel
  //
  this->salaryLabel->AutoSize = true;
  this->salaryLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->salaryLabel->Location = System::Drawing::Point(14, 401);
  this->salaryLabel->Name = L"salaryLabel";
  this->salaryLabel->Size = System::Drawing::Size(97, 37);
  this->salaryLabel->TabIndex = 22;
  this->salaryLabel->Text = L"Salary";
  //
  // employmentTypeComboBox
  //
  this->employmentTypeComboBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->employmentTypeComboBox->FormattingEnabled = true;
  this->employmentTypeComboBox->Items->AddRange(
      gcnew cli::array<System::Object ^>(3){L"Full Time", L"Part Time",
                                            L"Casual"});
  this->employmentTypeComboBox->Location = System::Drawing::Point(430, 347);
  this->employmentTypeComboBox->Name = L"employmentTypeComboBox";
  this->employmentTypeComboBox->Size = System::Drawing::Size(121, 45);
  this->employmentTypeComboBox->TabIndex = 21;
  //
  // salaryrichTextBox
  //
  this->salaryrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->salaryrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->salaryrichTextBox->Location = System::Drawing::Point(430, 410);
  this->salaryrichTextBox->MaxLength = 10;
  this->salaryrichTextBox->Name = L"salaryrichTextBox";
  this->salaryrichTextBox->Size = System::Drawing::Size(180, 48);
  this->salaryrichTextBox->TabIndex = 20;
  this->salaryrichTextBox->Text = L"";
  //
  // addressrichTextBox
  //
  this->addressrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->addressrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->addressrichTextBox->Location = System::Drawing::Point(430, 281);
  this->addressrichTextBox->MaxLength = 10;
  this->addressrichTextBox->Name = L"addressrichTextBox";
  this->addressrichTextBox->Size = System::Drawing::Size(558, 48);
  this->addressrichTextBox->TabIndex = 19;
  this->addressrichTextBox->Text = L"";
  //
  // agerichTextBox
  //
  this->agerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
  this->agerichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->agerichTextBox->Location = System::Drawing::Point(430, 215);
  this->agerichTextBox->MaxLength = 10;
  this->agerichTextBox->Name = L"agerichTextBox";
  this->agerichTextBox->Size = System::Drawing::Size(180, 48);
  this->agerichTextBox->TabIndex = 18;
  this->agerichTextBox->Text = L"";
  //
  // genderrichTextBox
  //
  this->genderrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->genderrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->genderrichTextBox->Location = System::Drawing::Point(430, 149);
  this->genderrichTextBox->MaxLength = 10;
  this->genderrichTextBox->Name = L"genderrichTextBox";
  this->genderrichTextBox->Size = System::Drawing::Size(180, 48);
  this->genderrichTextBox->TabIndex = 17;
  this->genderrichTextBox->Text = L"";
  //
  // employmenttypeLabel
  //
  this->employmenttypeLabel->AutoSize = true;
  this->employmenttypeLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->employmenttypeLabel->Location = System::Drawing::Point(16, 337);
  this->employmenttypeLabel->Name = L"employmenttypeLabel";
  this->employmenttypeLabel->Size = System::Drawing::Size(244, 37);
  this->employmenttypeLabel->TabIndex = 16;
  this->employmenttypeLabel->Text = L"Employment Type";
  //
  // addressLabel
  //
  this->addressLabel->AutoSize = true;
  this->addressLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->addressLabel->Location = System::Drawing::Point(16, 273);
  this->addressLabel->Name = L"addressLabel";
  this->addressLabel->Size = System::Drawing::Size(123, 37);
  this->addressLabel->TabIndex = 15;
  this->addressLabel->Text = L"Address";
  //
  // ageLabel
  //
  this->ageLabel->AutoSize = true;
  this->ageLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->ageLabel->Location = System::Drawing::Point(16, 209);
  this->ageLabel->Name = L"ageLabel";
  this->ageLabel->Size = System::Drawing::Size(67, 37);
  this->ageLabel->TabIndex = 14;
  this->ageLabel->Text = L"Age";
  //
  // genderLabel
  //
  this->genderLabel->AutoSize = true;
  this->genderLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->genderLabel->Location = System::Drawing::Point(16, 145);
  this->genderLabel->Name = L"genderLabel";
  this->genderLabel->Size = System::Drawing::Size(109, 37);
  this->genderLabel->TabIndex = 13;
  this->genderLabel->Text = L"Gender";
  //
  // lastnamerichTextBox
  //
  this->lastnamerichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->lastnamerichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->lastnamerichTextBox->Location = System::Drawing::Point(430, 83);
  this->lastnamerichTextBox->MaxLength = 10;
  this->lastnamerichTextBox->Name = L"lastnamerichTextBox";
  this->lastnamerichTextBox->Size = System::Drawing::Size(180, 48);
  this->lastnamerichTextBox->TabIndex = 12;
  this->lastnamerichTextBox->Text = L"";
  //
  // createnewadminButton
  //
  this->createnewadminButton->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->createnewadminButton->ForeColor = System::Drawing::Color::DodgerBlue;
  this->createnewadminButton->Location = System::Drawing::Point(311, 516);
  this->createnewadminButton->Name = L"createnewadminButton";
  this->createnewadminButton->Size = System::Drawing::Size(398, 45);
  this->createnewadminButton->TabIndex = 10;
  this->createnewadminButton->Text = L"Create New Admin";
  this->createnewadminButton->UseVisualStyleBackColor = true;
  this->createnewadminButton->Click +=
      gcnew System::EventHandler(this, &Main::createnewadminButton_Click);
  //
  // lastnameLabel
  //
  this->lastnameLabel->AutoSize = true;
  this->lastnameLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->lastnameLabel->Location = System::Drawing::Point(16, 81);
  this->lastnameLabel->Name = L"lastnameLabel";
  this->lastnameLabel->Size = System::Drawing::Size(151, 37);
  this->lastnameLabel->TabIndex = 8;
  this->lastnameLabel->Text = L"Last Name";
  //
  // firstnameLabel
  //
  this->firstnameLabel->AutoSize = true;
  this->firstnameLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->firstnameLabel->Location = System::Drawing::Point(14, 17);
  this->firstnameLabel->Name = L"firstnameLabel";
  this->firstnameLabel->Size = System::Drawing::Size(153, 37);
  this->firstnameLabel->TabIndex = 7;
  this->firstnameLabel->Text = L"First Name";
  //
  // firstnamerichTextBox
  //
  this->firstnamerichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->firstnamerichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->firstnamerichTextBox->Location = System::Drawing::Point(430, 17);
  this->firstnamerichTextBox->MaxLength = 10;
  this->firstnamerichTextBox->Name = L"firstnamerichTextBox";
  this->firstnamerichTextBox->Size = System::Drawing::Size(180, 48);
  this->firstnamerichTextBox->TabIndex = 9;
  this->firstnamerichTextBox->Text = L"";
  //
  // newWaiterPanel
  //
  this->newWaiterPanel->Controls->Add(this->waiterSalaryLabel);
  this->newWaiterPanel->Controls->Add(this->WaiterEmploymentTypeComboBox);
  this->newWaiterPanel->Controls->Add(this->waiterSalaryrichTextBox);
  this->newWaiterPanel->Controls->Add(this->waiterAddressrichTextBox);
  this->newWaiterPanel->Controls->Add(this->waiterAgerichTextBox);
  this->newWaiterPanel->Controls->Add(this->waiterGenderrichTextBox);
  this->newWaiterPanel->Controls->Add(this->waiterEmploymentTypeLabel);
  this->newWaiterPanel->Controls->Add(this->waiterAdressLabel);
  this->newWaiterPanel->Controls->Add(this->waiterAgeLabel);
  this->newWaiterPanel->Controls->Add(this->waiterGenderLabel);
  this->newWaiterPanel->Controls->Add(this->waiterLastNamerichTextBox);
  this->newWaiterPanel->Controls->Add(this->waiterCreateNewButton);
  this->newWaiterPanel->Controls->Add(this->waiterLastNameLabel);
  this->newWaiterPanel->Controls->Add(this->waiterFirstNameLabel);
  this->newWaiterPanel->Controls->Add(this->waiterFirstNamerichTextBox);
  this->newWaiterPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->newWaiterPanel->Location = System::Drawing::Point(80, 84);
  this->newWaiterPanel->Name = L"newWaiterPanel";
  this->newWaiterPanel->Size = System::Drawing::Size(1220, 614);
  this->newWaiterPanel->TabIndex = 14;
  this->newWaiterPanel->Visible = false;
  //
  // waiterSalaryLabel
  //
  this->waiterSalaryLabel->AutoSize = true;
  this->waiterSalaryLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->waiterSalaryLabel->Location = System::Drawing::Point(14, 401);
  this->waiterSalaryLabel->Name = L"waiterSalaryLabel";
  this->waiterSalaryLabel->Size = System::Drawing::Size(97, 37);
  this->waiterSalaryLabel->TabIndex = 22;
  this->waiterSalaryLabel->Text = L"Salary";
  //
  // WaiterEmploymentTypeComboBox
  //
  this->WaiterEmploymentTypeComboBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->WaiterEmploymentTypeComboBox->FormattingEnabled = true;
  this->WaiterEmploymentTypeComboBox->Items->AddRange(
      gcnew cli::array<System::Object ^>(3){L"Full Time", L"Part Time",
                                            L"Casual"});
  this->WaiterEmploymentTypeComboBox->Location =
      System::Drawing::Point(430, 347);
  this->WaiterEmploymentTypeComboBox->Name = L"WaiterEmploymentTypeComboBox";
  this->WaiterEmploymentTypeComboBox->Size = System::Drawing::Size(121, 45);
  this->WaiterEmploymentTypeComboBox->TabIndex = 21;
  //
  // waiterSalaryrichTextBox
  //
  this->waiterSalaryrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->waiterSalaryrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->waiterSalaryrichTextBox->Location = System::Drawing::Point(430, 410);
  this->waiterSalaryrichTextBox->MaxLength = 10;
  this->waiterSalaryrichTextBox->Name = L"waiterSalaryrichTextBox";
  this->waiterSalaryrichTextBox->Size = System::Drawing::Size(180, 48);
  this->waiterSalaryrichTextBox->TabIndex = 20;
  this->waiterSalaryrichTextBox->Text = L"";
  //
  // waiterAddressrichTextBox
  //
  this->waiterAddressrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->waiterAddressrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->waiterAddressrichTextBox->Location = System::Drawing::Point(430, 281);
  this->waiterAddressrichTextBox->MaxLength = 10;
  this->waiterAddressrichTextBox->Name = L"waiterAddressrichTextBox";
  this->waiterAddressrichTextBox->Size = System::Drawing::Size(558, 48);
  this->waiterAddressrichTextBox->TabIndex = 19;
  this->waiterAddressrichTextBox->Text = L"";
  //
  // waiterAgerichTextBox
  //
  this->waiterAgerichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->waiterAgerichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->waiterAgerichTextBox->Location = System::Drawing::Point(430, 215);
  this->waiterAgerichTextBox->MaxLength = 10;
  this->waiterAgerichTextBox->Name = L"waiterAgerichTextBox";
  this->waiterAgerichTextBox->Size = System::Drawing::Size(180, 48);
  this->waiterAgerichTextBox->TabIndex = 18;
  this->waiterAgerichTextBox->Text = L"";
  //
  // waiterGenderrichTextBox
  //
  this->waiterGenderrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->waiterGenderrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->waiterGenderrichTextBox->Location = System::Drawing::Point(430, 149);
  this->waiterGenderrichTextBox->MaxLength = 10;
  this->waiterGenderrichTextBox->Name = L"waiterGenderrichTextBox";
  this->waiterGenderrichTextBox->Size = System::Drawing::Size(180, 48);
  this->waiterGenderrichTextBox->TabIndex = 17;
  this->waiterGenderrichTextBox->Text = L"";
  //
  // waiterEmploymentTypeLabel
  //
  this->waiterEmploymentTypeLabel->AutoSize = true;
  this->waiterEmploymentTypeLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->waiterEmploymentTypeLabel->Location = System::Drawing::Point(16, 337);
  this->waiterEmploymentTypeLabel->Name = L"waiterEmploymentTypeLabel";
  this->waiterEmploymentTypeLabel->Size = System::Drawing::Size(244, 37);
  this->waiterEmploymentTypeLabel->TabIndex = 16;
  this->waiterEmploymentTypeLabel->Text = L"Employment Type";
  //
  // waiterAdressLabel
  //
  this->waiterAdressLabel->AutoSize = true;
  this->waiterAdressLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->waiterAdressLabel->Location = System::Drawing::Point(16, 273);
  this->waiterAdressLabel->Name = L"waiterAdressLabel";
  this->waiterAdressLabel->Size = System::Drawing::Size(123, 37);
  this->waiterAdressLabel->TabIndex = 15;
  this->waiterAdressLabel->Text = L"Address";
  //
  // waiterAgeLabel
  //
  this->waiterAgeLabel->AutoSize = true;
  this->waiterAgeLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->waiterAgeLabel->Location = System::Drawing::Point(16, 209);
  this->waiterAgeLabel->Name = L"waiterAgeLabel";
  this->waiterAgeLabel->Size = System::Drawing::Size(67, 37);
  this->waiterAgeLabel->TabIndex = 14;
  this->waiterAgeLabel->Text = L"Age";
  //
  // waiterGenderLabel
  //
  this->waiterGenderLabel->AutoSize = true;
  this->waiterGenderLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->waiterGenderLabel->Location = System::Drawing::Point(16, 145);
  this->waiterGenderLabel->Name = L"waiterGenderLabel";
  this->waiterGenderLabel->Size = System::Drawing::Size(109, 37);
  this->waiterGenderLabel->TabIndex = 13;
  this->waiterGenderLabel->Text = L"Gender";
  //
  // waiterLastNamerichTextBox
  //
  this->waiterLastNamerichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->waiterLastNamerichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->waiterLastNamerichTextBox->Location = System::Drawing::Point(430, 83);
  this->waiterLastNamerichTextBox->MaxLength = 10;
  this->waiterLastNamerichTextBox->Name = L"waiterLastNamerichTextBox";
  this->waiterLastNamerichTextBox->Size = System::Drawing::Size(180, 48);
  this->waiterLastNamerichTextBox->TabIndex = 12;
  this->waiterLastNamerichTextBox->Text = L"";
  //
  // waiterCreateNewButton
  //
  this->waiterCreateNewButton->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->waiterCreateNewButton->ForeColor = System::Drawing::Color::DodgerBlue;
  this->waiterCreateNewButton->Location = System::Drawing::Point(311, 516);
  this->waiterCreateNewButton->Name = L"waiterCreateNewButton";
  this->waiterCreateNewButton->Size = System::Drawing::Size(398, 45);
  this->waiterCreateNewButton->TabIndex = 10;
  this->waiterCreateNewButton->Text = L"Create New Waiter";
  this->waiterCreateNewButton->UseVisualStyleBackColor = true;
  this->waiterCreateNewButton->Click +=
      gcnew System::EventHandler(this, &Main::waiterCreateNewButton_Click);
  //
  // waiterLastNameLabel
  //
  this->waiterLastNameLabel->AutoSize = true;
  this->waiterLastNameLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->waiterLastNameLabel->Location = System::Drawing::Point(16, 81);
  this->waiterLastNameLabel->Name = L"waiterLastNameLabel";
  this->waiterLastNameLabel->Size = System::Drawing::Size(151, 37);
  this->waiterLastNameLabel->TabIndex = 8;
  this->waiterLastNameLabel->Text = L"Last Name";
  //
  // waiterFirstNameLabel
  //
  this->waiterFirstNameLabel->AutoSize = true;
  this->waiterFirstNameLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->waiterFirstNameLabel->Location = System::Drawing::Point(14, 17);
  this->waiterFirstNameLabel->Name = L"waiterFirstNameLabel";
  this->waiterFirstNameLabel->Size = System::Drawing::Size(153, 37);
  this->waiterFirstNameLabel->TabIndex = 7;
  this->waiterFirstNameLabel->Text = L"First Name";
  //
  // waiterFirstNamerichTextBox
  //
  this->waiterFirstNamerichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->waiterFirstNamerichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->waiterFirstNamerichTextBox->Location = System::Drawing::Point(430, 17);
  this->waiterFirstNamerichTextBox->MaxLength = 10;
  this->waiterFirstNamerichTextBox->Name = L"waiterFirstNamerichTextBox";
  this->waiterFirstNamerichTextBox->Size = System::Drawing::Size(180, 48);
  this->waiterFirstNamerichTextBox->TabIndex = 9;
  this->waiterFirstNamerichTextBox->Text = L"";
  //
  // CurrentTimeTimer
  //
  this->CurrentTimeTimer->Tick +=
      gcnew System::EventHandler(this, &Main::timer1_Tick);
  //
  // tablesLayoutPanel
  //
  bool activate;
  this->tablesLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->tablesLayoutPanel->Location = System::Drawing::Point(80, 84);
  this->tablesLayoutPanel->Name = L"tablesLayoutPanel";
  this->tablesLayoutPanel->Size = System::Drawing::Size(1220, 614);
  this->tablesLayoutPanel->TabIndex = 0;
  this->tablesLayoutPanel->MouseDown +=
      gcnew System::Windows::Forms::MouseEventHandler(this, &Main::addTables);
  //
  // newTablesPanel
  //
  this->newTablesPanel->Controls->Add(this->createNewTableButton);
  this->newTablesPanel->Controls->Add(this->tablesSeatsLabel);
  this->newTablesPanel->Controls->Add(this->tablesSeatsrichTextBox);
  this->newTablesPanel->Dock = System::Windows::Forms::DockStyle::Fill;
  this->newTablesPanel->Location = System::Drawing::Point(80, 84);
  this->newTablesPanel->Name = L"newTablesPanel";
  this->newTablesPanel->Size = System::Drawing::Size(1220, 614);
  this->newTablesPanel->TabIndex = 13;
  //
  // createNewTableButton
  //
  this->createNewTableButton->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->createNewTableButton->ForeColor = System::Drawing::Color::DodgerBlue;
  this->createNewTableButton->Location = System::Drawing::Point(340, 460);
  this->createNewTableButton->Name = L"createNewTableButton";
  this->createNewTableButton->Size = System::Drawing::Size(398, 45);
  this->createNewTableButton->TabIndex = 12;
  this->createNewTableButton->Text = L"Create New Table";
  this->createNewTableButton->UseVisualStyleBackColor = true;
  this->createNewTableButton->Click +=
      gcnew System::EventHandler(this, &Main::createNewTableButton_Click);
  //
  // tablesSeatsLabel
  //
  this->tablesSeatsLabel->AutoSize = true;
  this->tablesSeatsLabel->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
      System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
  this->tablesSeatsLabel->Location = System::Drawing::Point(7, 17);
  this->tablesSeatsLabel->Name = L"tablesSeatsLabel";
  this->tablesSeatsLabel->Size = System::Drawing::Size(177, 37);
  this->tablesSeatsLabel->TabIndex = 10;
  this->tablesSeatsLabel->Text = L"Tables seats";
  //
  // tablesSeatsrichTextBox
  //
  this->tablesSeatsrichTextBox->BorderStyle =
      System::Windows::Forms::BorderStyle::None;
  this->tablesSeatsrichTextBox->Font = (gcnew System::Drawing::Font(
      L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
  this->tablesSeatsrichTextBox->Location = System::Drawing::Point(423, 17);
  this->tablesSeatsrichTextBox->MaxLength = 10;
  this->tablesSeatsrichTextBox->Name = L"tablesSeatsrichTextBox";
  this->tablesSeatsrichTextBox->Size = System::Drawing::Size(180, 48);
  this->tablesSeatsrichTextBox->TabIndex = 11;
  this->tablesSeatsrichTextBox->Text = L"";
  //
  // Main
  //
  this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
  this->ClientSize = System::Drawing::Size(1300, 782);
  this->Controls->Add(this->tablesLayoutPanel);
  this->Controls->Add(this->newTablesPanel);
  this->Controls->Add(this->adminPanel);
  this->Controls->Add(this->newWaiterPanel);
  this->Controls->Add(this->drinksMenuPanel);
  this->Controls->Add(this->clockinPanel);
  this->Controls->Add(this->adminLoginPanel);
  this->Controls->Add(this->newAdminPanel);
  this->Controls->Add(this->dessertMenuPanel);
  this->Controls->Add(this->mainMenuPanel);
  this->Controls->Add(this->entreeMenuPanel);
  this->Controls->Add(this->addItemPanel);
  this->Controls->Add(this->headerPanel);
  this->Controls->Add(this->footerPanel);
  this->Controls->Add(this->sidePanel);
  this->Name = L"Main";
  this->Text = L"Main";
  this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
  this->sidePanel->ResumeLayout(false);
  this->adminPanel->ResumeLayout(false);
  this->contactPanel->ResumeLayout(false);
  this->contactPanel->PerformLayout();
  (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Contact))
      ->EndInit();
  this->removePanel->ResumeLayout(false);
  this->removePanel->PerformLayout();
  (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Remove))
      ->EndInit();
  this->addPanel->ResumeLayout(false);
  this->addPanel->PerformLayout();
  (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Add))
      ->EndInit();
  this->footerPanel->ResumeLayout(false);
  this->footerPanel->PerformLayout();
  this->headerPanel->ResumeLayout(false);
  this->headerPanel->PerformLayout();
  this->clockinPanel->ResumeLayout(false);
  this->clockinPanel->PerformLayout();
  this->adminLoginPanel->ResumeLayout(false);
  this->adminLoginPanel->PerformLayout();
  this->addItemPanel->ResumeLayout(false);
  this->addItemPanel->PerformLayout();
  this->newAdminPanel->ResumeLayout(false);
  this->newAdminPanel->PerformLayout();
  this->newWaiterPanel->ResumeLayout(false);
  this->newWaiterPanel->PerformLayout();
  this->newTablesPanel->ResumeLayout(false);
  this->newTablesPanel->PerformLayout();
  this->ResumeLayout(false);
  this->PerformLayout();
}

System::Void RMSPOS::Main::clockButton_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
  clockinPanel->Left = (this->ClientSize.Width - clockinPanel->Width) / 2;
  clockinPanel->Top = (this->ClientSize.Height - clockinPanel->Height) / 2;
  hideAll();
  clockinPanel->Show();
}

System::Void RMSPOS::Main::adminButton_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
  if (Admin::adminsVector.size() == 0) {
    if (MessageBox::Show("It appears there are no appointed admins yet. "
                         "Would you like to create admin account?",
                         "Confirm", MessageBoxButtons::YesNo) ==
        System::Windows::Forms::DialogResult::Yes) {
      adminLoginPanel->Left =
          (this->ClientSize.Width - adminLoginPanel->Width) / 2;
      adminLoginPanel->Top =
          (this->ClientSize.Height - adminLoginPanel->Height) / 2;
      hideAll();
      newAdminPanel->Show();
    }
  } else {
    adminLoginPanel->Left =
        (this->ClientSize.Width - adminLoginPanel->Width) / 2;
    adminLoginPanel->Top =
        (this->ClientSize.Height - adminLoginPanel->Height) / 2;
    hideAll();
    adminLoginPanel->Show();
  }
}

System::Void RMSPOS::Main::LoginButton_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
  std::vector<Admin>::iterator iter1, iter2, end1, end2;
  for (iter1 = Admin::adminsVector.begin(), end1 = Admin::adminsVector.end();
       iter1 != end1; ++iter1) {
    string inputUsername = (iter1)->getUsername();
    string inputPassword = (iter1)->getPassword();
    /*std::cout << inputUsername << endl;*/
    if ((iter1)->getUsername() ==
            marshal_as<std::string>(adminNumberrichTextBox->Text) &&
        (iter1)->getPassword() ==
            marshal_as<std::string>(adminPasswordrichTextBox->Text)) {
      hideAll();
      adminPanel->Show();
      loginFailedLabel->Hide();
      break;
    } else {
      loginFailedLabel->Show();
    }
  }
}

System::Void RMSPOS::Main::drinkButton_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
  hideAll();
  drinksMenuPanel->Show();
}

System::Void RMSPOS::Main::addMenuItemButton_Click(System::Object ^ sender,
                                                   System::EventArgs ^ e) {
  hideAll();
  addItemPanel->Show();
}

System::Void RMSPOS::Main::addDrinkButton_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {

  std::string std_itemNamerichTextBox =
      marshal_as<std::string>(itemNamerichTextBox->Text);
  int itemPrice = Convert::ToInt32(itemPricerichTextBox->Text);
  std::string std_itemCategory = marshal_as<std::string>(itemCategory->Text);
  if (std_itemCategory == "Drink") {
    Drink newDrink(std_itemNamerichTextBox, itemPrice, true);
    System::Windows::Forms::Button ^ button;
    button = (gcnew System::Windows::Forms::Button());
    this->drinksMenuPanel->Controls->Add(button, 0, 0);
    button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    button->Location = System::Drawing::Point(3, 3);
    button->Text = itemNamerichTextBox->Text;
    button->Font = (gcnew System::Drawing::Font(
        L"Arial Narrow", 10, System::Drawing::FontStyle::Bold));
    button->Size = System::Drawing::Size(71, 75);
    button->TabIndex = 1;
    button->UseVisualStyleBackColor = true;
    button->Visible = newDrink.getvisible();
    hideAll();
    drinksMenuPanel->Show();
  } else if (std_itemCategory == "Entree") {
    Entree newEntree(std_itemNamerichTextBox, itemPrice, true);
    System::Windows::Forms::Button ^ button;
    button = (gcnew System::Windows::Forms::Button());
    this->entreeMenuPanel->Controls->Add(button, 0, 0);
    button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    button->Location = System::Drawing::Point(3, 3);
    button->Text = itemNamerichTextBox->Text;
    button->Font = (gcnew System::Drawing::Font(
        L"Arial Narrow", 10, System::Drawing::FontStyle::Bold));
    button->Size = System::Drawing::Size(71, 75);
    button->TabIndex = 1;
    button->UseVisualStyleBackColor = true;
    button->Visible = newEntree.getvisible();

    hideAll();
    entreeMenuPanel->Show();
  } else if (std_itemCategory == "Main") {
    Mains newMain(std_itemNamerichTextBox, itemPrice, true);
    System::Windows::Forms::Button ^ button;
    button = (gcnew System::Windows::Forms::Button());
    this->mainMenuPanel->Controls->Add(button, 0, 0);
    button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    button->Location = System::Drawing::Point(3, 3);
    button->Text = itemNamerichTextBox->Text;
    button->Font = (gcnew System::Drawing::Font(
        L"Arial Narrow", 10, System::Drawing::FontStyle::Bold));
    button->Size = System::Drawing::Size(71, 75);
    button->TabIndex = 1;
    button->UseVisualStyleBackColor = true;
    button->Visible = newMain.getvisible();

    hideAll();
    mainMenuPanel->Show();
  } else if (std_itemCategory == "Dessert") {
    Dessert newDessert(std_itemNamerichTextBox, itemPrice, true);
    System::Windows::Forms::Button ^ button;
    button = (gcnew System::Windows::Forms::Button());
    this->dessertMenuPanel->Controls->Add(button, 0, 0);
    button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    button->Location = System::Drawing::Point(3, 3);
    button->Text = itemNamerichTextBox->Text;
    button->Font = (gcnew System::Drawing::Font(
        L"Arial Narrow", 10, System::Drawing::FontStyle::Bold));
    button->Size = System::Drawing::Size(71, 75);
    button->TabIndex = 1;
    button->UseVisualStyleBackColor = true;
    button->Visible = newDessert.getvisible();
    hideAll();
    dessertMenuPanel->Show();
  } else {
    errorLabel->Visible = true;
  }
}

System::Void RMSPOS::Main::entreeButton_Click(System::Object ^ sender,
                                              System::EventArgs ^ e) {

  hideAll();
  entreeMenuPanel->Show();
}

System::Void RMSPOS::Main::mainButton_Click(System::Object ^ sender,
                                            System::EventArgs ^ e) {

  hideAll();
  mainMenuPanel->Show();
}

System::Void RMSPOS::Main::dessertButton_Click(System::Object ^ sender,
                                               System::EventArgs ^ e) {
  hideAll();
  dessertMenuPanel->Show();
}

System::Void RMSPOS::Main::addManagerButton_Click(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
  hideAll();
  newAdminPanel->Show();
}

System::Void RMSPOS::Main::createnewadminButton_Click(System::Object ^ sender,
                                                      System::EventArgs ^ e) {
  try {
    std::string std_firstnameAdmin =
        marshal_as<std::string>(firstnamerichTextBox->Text);
    std::string std_lastnameAdmin =
        marshal_as<std::string>(lastnamerichTextBox->Text);
    int std_salaryAdmin = Convert::ToInt32(salaryrichTextBox->Text);
    int std_ageAdmin = Convert::ToInt32(agerichTextBox->Text);
    std::string std_genderAdmin =
        marshal_as<std::string>(genderrichTextBox->Text);
    std::string std_addressAdmin =
        marshal_as<std::string>(addressrichTextBox->Text);
    std::string std_employmenttypeAdmin =
        marshal_as<std::string>(employmentTypeComboBox->Text);
    Admin newAdmin(std_firstnameAdmin, std_lastnameAdmin, std_salaryAdmin,
                   std_ageAdmin, std_genderAdmin, std_addressAdmin,
                   std_employmenttypeAdmin);
    String ^ newAdminUsername = gcnew String(newAdmin.getUsername().c_str());
    String ^ newAdminPassword = gcnew String(newAdmin.getPassword().c_str());
    String ^ msg = "Admin has been created successfully!\n\nThe following "
                   "credentials have been created for them automatically. "
                   "Next time they log in, they will be asked to change "
                   "their credentials to a more secured ones.\n\nUsername: " +
                   newAdminUsername + "\nPassword: " + newAdminPassword;
    MessageBox::Show(msg);
    Admin::adminsVector.push_back(newAdmin);
    hideAll();
    adminPanel->Show();
  }

  catch (...)

  {
    String ^ msg = "Admin has not been created successfully!\n\nPlease check "
                   "your details are correct.";
    MessageBox::Show(msg);
  }
}

System::Void RMSPOS::Main::addWaiterButton_Click(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
  hideAll();
  newWaiterPanel->Show();
}

System::Void RMSPOS::Main::waiterCreateNewButton_Click(System::Object ^ sender,
                                                       System::EventArgs ^ e) {

  try {
    std::string std_firstnameWaiter =
        marshal_as<std::string>(waiterFirstNamerichTextBox->Text);
    std::string std_lastnameWaiter =
        marshal_as<std::string>(waiterLastNamerichTextBox->Text);
    int std_salaryWaiter = Convert::ToInt32(waiterSalaryrichTextBox->Text);
    int std_ageWaiter = Convert::ToInt32(waiterAgerichTextBox->Text);
    std::string std_genderWaiter =
        marshal_as<std::string>(waiterGenderrichTextBox->Text);
    std::string std_addressWaiter =
        marshal_as<std::string>(waiterAddressrichTextBox->Text);
    std::string std_employmenttypeWaiter =
        marshal_as<std::string>(WaiterEmploymentTypeComboBox->Text);
    Waiter newWaiter(std_firstnameWaiter, std_lastnameWaiter, std_salaryWaiter,
                     std_ageWaiter, std_genderWaiter, std_addressWaiter,
                     std_employmenttypeWaiter);
    newWaiter.changeCredentials(newWaiter.getInitials(),
                                newWaiter.generateID());
    String ^ newWaiternUsername = gcnew String(newWaiter.getInitials().c_str());
    String ^ newWaiterPassword = gcnew String(newWaiter.getPassword().c_str());
    String ^ msg = "Waiter has been created successfully!\n\nThey will need "
                   "these details to clock in and clock out.\n\nInitials: " +
                   newWaiternUsername + "\nPassword: " + newWaiterPassword;
    MessageBox::Show(msg);
    Waiter::waitersVector.push_back(newWaiter);
    hideAll();
    adminPanel->Show();
  }

  catch (...)

  {
    String ^ msg = "Waiter has not been created successfully!\n\nPlease check "
                   "your details are correct.";
    MessageBox::Show(msg);
  }
}

System::Void RMSPOS::Main::clockinButton_Click(System::Object ^ sender,
                                               System::EventArgs ^ e) {
  vector<Waiter>::iterator iter1, end1;
  bool loginSuccessful = false;
  for (iter1 = Waiter::waitersVector.begin(),
      end1 = Waiter::waitersVector.end();
       iter1 != end1; ++iter1) {
    if (iter1->getUsername() ==
            marshal_as<std::string>(staffnumberrichTextBox->Text) &&
        marshal_as<std::string>(staffpasswordrichTextBox->Text) ==
            iter1->getPassword()) {
      String ^ firstName = gcnew String((iter1)->getFirstName().c_str());
      loginSuccessful = true;
      Waiter::clockedinWaiters.push_back(*iter1);
      String ^ timeNow = getTime();
      String ^ msg = "Hello " + firstName +
                     "!\n\nYou successfully clocked in at " + timeNow;
      MessageBox::Show(msg);
      clockinFailedLabel->Hide();
      break;
    }
  }

  if (!loginSuccessful) {
    clockinFailedLabel->Show();
  }
}

System::Void RMSPOS::Main::timer1_Tick(System::Object ^ sender,
                                       System::EventArgs ^ e) {
  DateTime datetime = DateTime::Now;
  footerTimeValueLabel->Text = datetime.ToLongTimeString();
  footerDateValueLabel->Text = datetime.ToString("dd/MM/yyyy");
  footerStaffValueLabel->Text =
      Convert::ToString(Waiter::clockedinWaiters.size());
}

System::Void RMSPOS::Main::addNewTableButton_Click(System::Object ^ sender,
                                                   System::EventArgs ^ e) {
  hideAll();
  newTablesPanel->Show();
}

System::Void RMSPOS::Main::createNewTableButton_Click(System::Object ^ sender,
                                                      System::EventArgs ^ e) {
  createNewTableButton->Tag = "Activate";
  String ^ msg = "Please use the mouse left button to indicate where you want "
                 "the new table to be positioned.";
  MessageBox::Show(msg);
  hideAll();
  tablesLayoutPanel->Show();
}

System::Void RMSPOS::Main::tablesButton_Click(System::Object ^ sender,
                                              System::EventArgs ^ e) {
  hideAll();
  tablesLayoutPanel->Show();
  bool activate = true;
}

System::Void RMSPOS::Main::addTables(System::Object ^ sender,
                                     System::Windows::Forms::MouseEventArgs ^
                                         e) {
  if (createNewTableButton->Tag == "Activate") {

    try {

      Table newTable(Convert::ToInt32(tablesSeatsrichTextBox->Text));
      Table::tablesVector.push_back(newTable);
      Button ^ newButton = gcnew Button();
      newButton->Font = (gcnew System::Drawing::Font(
          L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold,
          System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
      newButton->Text =
          Convert::ToString("Table " + Table::tablesVector.size());
      newButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
          (System::Windows::Forms::AnchorStyles::Bottom |
           System::Windows::Forms::AnchorStyles::Left |
           System::Windows::Forms::AnchorStyles::Right |
           System::Windows::Forms::AnchorStyles::Bottom));
      newButton->BackColor = System::Drawing::SystemColors::ControlLight;
      newButton->Location = System::Drawing::Point(
          e->Location.X - Convert::ToInt32(newButton->Size.Width),
          e->Location.Y - Convert::ToInt32(newButton->Size.Height));
      newButton->Size = System::Drawing::Size(100, 100);
      newButton->TabIndex = 0;
      newButton->UseVisualStyleBackColor = false;
      this->tablesLayoutPanel->Controls->Add(newButton);
      hideAll();
      tablesLayoutPanel->Show();
      createNewTableButton->Tag = "Deactivate";
      String ^ msg = "Table has been created successfully!";
      MessageBox::Show(msg);
    }

    catch (...) {
      String ^ msg =
          "Table has not been created successfully! Please try again.";
      MessageBox::Show(msg);
      hideAll();
      newTablesPanel->Show();
    }
  }
}
