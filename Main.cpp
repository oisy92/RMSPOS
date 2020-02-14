#include "pch.h"
#include "Main.h"
#include "Admin.h"
#include "Waiter.h"
#include "Table.h"
#include "Drink.h"
#include "Entree.h"
#include "Mains.h"
#include "Dessert.h"
#include "Functions.h"

vector<Admin> Admin::adminsVector;
vector<Waiter> Waiter::waitersVector;
vector<Waiter> Waiter::clockedinWaiters;
vector<Table> Table::tablesVector;
vector<pair<string, int>> Menu::menuVector;
vector<pair<string, int>> Table::tempTableOrder;
string Table::activeTable;
using namespace System;

RMSPOS::Main::Main(void)
{
    InitializeComponent();
    CurrentTimeTimer->Start();
}

void RMSPOS::Main::hideAll()
{
    for (int i = 0; i <= Controls->Count - 1; i++)
    {
        std::string std_itemNamerichTextBox = toUnmannged(Controls->GetType()->ToString());
        if (Controls[i]->Name->Contains("footer") || Controls[i]->Name->Contains("header") ||
            Controls[i]->Name->Contains("side"))
        {
            Controls[i]->Show();
        }
        else
        {
            Controls[i]->Hide();
        }
    }
}

String ^ RMSPOS::Main::getDate()
{
    DateTime date = DateTime::Now;
    String ^ dateString = date.ToString("dd/mm/yyyy");
    return dateString;
}

String ^ RMSPOS::Main::getTime()
{
    DateTime time = DateTime::Now;
    String ^ timeString = time.ToLongTimeString();
    return timeString;
}

void RMSPOS::Main::InitializeComponent(void)
{
    this->components = (gcnew System::ComponentModel::Container());
    System::ComponentModel::ComponentResourceManager ^ resources =
        (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
    this->sidePanel = (gcnew System::Windows::Forms::Panel());
    this->viewOrderPanel = (gcnew System::Windows::Forms::Panel());
    this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->tableOrderItemPrice = (gcnew System::Windows::Forms::Label());
    this->tableOrderItemName = (gcnew System::Windows::Forms::Label());
    this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->tableOrderTotalPrice = (gcnew System::Windows::Forms::Label());
    this->tableOrderTotalName = (gcnew System::Windows::Forms::Label());
    this->tableOrderLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->tableOrderPayButton = (gcnew System::Windows::Forms::Button());
    this->orderPanel = (gcnew System::Windows::Forms::Panel());
    this->orderPanelFooterTotalString = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->label2 = (gcnew System::Windows::Forms::Label());
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->orderPanelFooter = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->orderPanelFooterTotalInt = (gcnew System::Windows::Forms::Label());
    this->orderPanelFooterT = (gcnew System::Windows::Forms::Label());
    this->eatoutOrderLayoutPanelTableLabel = (gcnew System::Windows::Forms::Button());
    this->clearOrderLayoutPanelTableLabel = (gcnew System::Windows::Forms::Button());
    this->eatinOrderLayoutPanelTableLabel = (gcnew System::Windows::Forms::Button());
    this->orderLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->confirmOrderLayoutPanelTableLabel = (gcnew System::Windows::Forms::Button());
    this->navigationPanel = (gcnew System::Windows::Forms::Panel());
    this->tablesButton = (gcnew System::Windows::Forms::Button());
    this->adminButton = (gcnew System::Windows::Forms::Button());
    this->clockButton = (gcnew System::Windows::Forms::Button());
    this->dessertButton = (gcnew System::Windows::Forms::Button());
    this->mainButton = (gcnew System::Windows::Forms::Button());
    this->entreeButton = (gcnew System::Windows::Forms::Button());
    this->drinkButton = (gcnew System::Windows::Forms::Button());
    this->sidePanelHeaderPanel = (gcnew System::Windows::Forms::Panel());
    this->headerSoftwareNameLabel = (gcnew System::Windows::Forms::Label());
    this->adminPanel = (gcnew System::Windows::Forms::Panel());
    this->removePanel = (gcnew System::Windows::Forms::Panel());
    this->button2 = (gcnew System::Windows::Forms::Button());
    this->removeManagerButton = (gcnew System::Windows::Forms::Button());
    this->removeWaiterButton = (gcnew System::Windows::Forms::Button());
    this->removeMenuItemButton = (gcnew System::Windows::Forms::Button());
    this->Remove = (gcnew System::Windows::Forms::PictureBox());
    this->contactPanel = (gcnew System::Windows::Forms::Panel());
    this->Contact = (gcnew System::Windows::Forms::PictureBox());
    this->orderSuppliesButton = (gcnew System::Windows::Forms::Button());
    this->addPanel = (gcnew System::Windows::Forms::Panel());
    this->addNewTableButton = (gcnew System::Windows::Forms::Button());
    this->addManagerButton = (gcnew System::Windows::Forms::Button());
    this->addWaiterButton = (gcnew System::Windows::Forms::Button());
    this->addMenuItemButton = (gcnew System::Windows::Forms::Button());
    this->Add = (gcnew System::Windows::Forms::PictureBox());
    this->headerPanel = (gcnew System::Windows::Forms::Panel());
    this->headerNavigationLabel = (gcnew System::Windows::Forms::Label());
    this->clockinPanel = (gcnew System::Windows::Forms::Panel());
    this->clockinFailedLabel = (gcnew System::Windows::Forms::Label());
    this->staffpasswordrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->clockOutbutton = (gcnew System::Windows::Forms::Button());
    this->clockinButton = (gcnew System::Windows::Forms::Button());
    this->staffpasswordLabel = (gcnew System::Windows::Forms::Label());
    this->staffnumberLabel = (gcnew System::Windows::Forms::Label());
    this->staffnumberrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->adminLoginPanel = (gcnew System::Windows::Forms::Panel());
    this->loginFailedLabel = (gcnew System::Windows::Forms::Label());
    this->adminPasswordrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
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
    this->firstnameLabel = (gcnew System::Windows::Forms::Label());
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
    this->firstnamerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->newWaiterPanel = (gcnew System::Windows::Forms::Panel());
    this->waiterSalaryLabel = (gcnew System::Windows::Forms::Label());
    this->WaiterEmploymentTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
    this->waiterSalaryrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->waiterAddressrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->waiterAgerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->waiterGenderrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->waiterEmploymentTypeLabel = (gcnew System::Windows::Forms::Label());
    this->waiterAdressLabel = (gcnew System::Windows::Forms::Label());
    this->waiterAgeLabel = (gcnew System::Windows::Forms::Label());
    this->waiterGenderLabel = (gcnew System::Windows::Forms::Label());
    this->waiterLastNamerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->waiterCreateNewButton = (gcnew System::Windows::Forms::Button());
    this->waiterLastNameLabel = (gcnew System::Windows::Forms::Label());
    this->waiterFirstNameLabel = (gcnew System::Windows::Forms::Label());
    this->waiterFirstNamerichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->CurrentTimeTimer = (gcnew System::Windows::Forms::Timer(this->components));
    this->tablesLayoutPanel = (gcnew System::Windows::Forms::Panel());
    this->newTablesPanel = (gcnew System::Windows::Forms::Panel());
    this->createNewTableButton = (gcnew System::Windows::Forms::Button());
    this->tablesSeatsLabel = (gcnew System::Windows::Forms::Label());
    this->tablesSeatsrichTextBox = (gcnew System::Windows::Forms::RichTextBox());
    this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->footerTimeLabel = (gcnew System::Windows::Forms::Label());
    this->footerTimeValueLabel = (gcnew System::Windows::Forms::Label());
    this->footerDateValueLabel = (gcnew System::Windows::Forms::Label());
    this->footerDatelabel = (gcnew System::Windows::Forms::Label());
    this->footerVacantTablesValueLabel = (gcnew System::Windows::Forms::Label());
    this->footerVacantTableslabel = (gcnew System::Windows::Forms::Label());
    this->footerStaffValueLabel = (gcnew System::Windows::Forms::Label());
    this->footerStafflabel = (gcnew System::Windows::Forms::Label());
    this->statusPanel = (gcnew System::Windows::Forms::Panel());
    this->statusLabel = (gcnew System::Windows::Forms::Label());
    this->footerPanel = (gcnew System::Windows::Forms::Panel());
    this->sidePanel->SuspendLayout();
    this->viewOrderPanel->SuspendLayout();
    this->tableLayoutPanel2->SuspendLayout();
    this->tableLayoutPanel3->SuspendLayout();
    this->orderPanel->SuspendLayout();
    this->orderPanelFooterTotalString->SuspendLayout();
    this->orderPanelFooter->SuspendLayout();
    this->navigationPanel->SuspendLayout();
    this->sidePanelHeaderPanel->SuspendLayout();
    this->adminPanel->SuspendLayout();
    this->removePanel->SuspendLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Remove))->BeginInit();
    this->contactPanel->SuspendLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Contact))->BeginInit();
    this->addPanel->SuspendLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Add))->BeginInit();
    this->headerPanel->SuspendLayout();
    this->clockinPanel->SuspendLayout();
    this->adminLoginPanel->SuspendLayout();
    this->addItemPanel->SuspendLayout();
    this->newAdminPanel->SuspendLayout();
    this->newWaiterPanel->SuspendLayout();
    this->newTablesPanel->SuspendLayout();
    this->tableLayoutPanel1->SuspendLayout();
    this->statusPanel->SuspendLayout();
    this->footerPanel->SuspendLayout();
    this->SuspendLayout();
    //
    // sidePanel
    //
    this->sidePanel->AutoSize = true;
    this->sidePanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->sidePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->sidePanel->Controls->Add(this->viewOrderPanel);
    this->sidePanel->Controls->Add(this->orderPanel);
    this->sidePanel->Controls->Add(this->navigationPanel);
    this->sidePanel->Controls->Add(this->sidePanelHeaderPanel);
    this->sidePanel->Dock = System::Windows::Forms::DockStyle::Left;
    this->sidePanel->Location = System::Drawing::Point(0, 102);
    this->sidePanel->Name = L"sidePanel";
    this->sidePanel->Size = System::Drawing::Size(396, 625);
    this->sidePanel->TabIndex = 0;
    //
    // viewOrderPanel
    //
    this->viewOrderPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
         System::Windows::Forms::AnchorStyles::Left));
    this->viewOrderPanel->Controls->Add(this->tableLayoutPanel2);
    this->viewOrderPanel->Controls->Add(this->tableLayoutPanel3);
    this->viewOrderPanel->Controls->Add(this->tableOrderLayoutPanel);
    this->viewOrderPanel->Controls->Add(this->tableOrderPayButton);
    this->viewOrderPanel->Location = System::Drawing::Point(5, 280);
    this->viewOrderPanel->Name = L"viewOrderPanel";
    this->viewOrderPanel->Size = System::Drawing::Size(384, 337);
    this->viewOrderPanel->TabIndex = 18;
    this->viewOrderPanel->Visible = false;
    //
    // tableLayoutPanel2
    //
    this->tableLayoutPanel2->ColumnCount = 2;
    this->tableLayoutPanel2->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 75.49857F)));
    this->tableLayoutPanel2->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 24.50142F)));
    this->tableLayoutPanel2->Controls->Add(this->tableOrderItemPrice, 1, 0);
    this->tableLayoutPanel2->Controls->Add(this->tableOrderItemName, 0, 0);
    this->tableLayoutPanel2->Location = System::Drawing::Point(5, 3);
    this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
    this->tableLayoutPanel2->RowCount = 1;
    this->tableLayoutPanel2->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
    this->tableLayoutPanel2->Size = System::Drawing::Size(353, 30);
    this->tableLayoutPanel2->TabIndex = 15;
    //
    // tableOrderItemPrice
    //
    this->tableOrderItemPrice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->tableOrderItemPrice->AutoSize = true;
    this->tableOrderItemPrice->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->tableOrderItemPrice->ForeColor = System::Drawing::SystemColors::ButtonFace;
    this->tableOrderItemPrice->Location = System::Drawing::Point(269, 0);
    this->tableOrderItemPrice->Name = L"tableOrderItemPrice";
    this->tableOrderItemPrice->Size = System::Drawing::Size(81, 30);
    this->tableOrderItemPrice->TabIndex = 1;
    this->tableOrderItemPrice->Text = L"Price";
    this->tableOrderItemPrice->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // tableOrderItemName
    //
    this->tableOrderItemName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->tableOrderItemName->AutoSize = true;
    this->tableOrderItemName->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->tableOrderItemName->ForeColor = System::Drawing::SystemColors::ButtonFace;
    this->tableOrderItemName->Location = System::Drawing::Point(3, 0);
    this->tableOrderItemName->Name = L"tableOrderItemName";
    this->tableOrderItemName->Size = System::Drawing::Size(260, 30);
    this->tableOrderItemName->TabIndex = 0;
    this->tableOrderItemName->Text = L"Item";
    this->tableOrderItemName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // tableLayoutPanel3
    //
    this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->tableLayoutPanel3->ColumnCount = 2;
    this->tableLayoutPanel3->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 74.66307F)));
    this->tableLayoutPanel3->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25.33693F)));
    this->tableLayoutPanel3->Controls->Add(this->tableOrderTotalPrice, 1, 0);
    this->tableLayoutPanel3->Controls->Add(this->tableOrderTotalName, 0, 0);
    this->tableLayoutPanel3->Location = System::Drawing::Point(5, 251);
    this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
    this->tableLayoutPanel3->RowCount = 1;
    this->tableLayoutPanel3->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
    this->tableLayoutPanel3->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
    this->tableLayoutPanel3->Size = System::Drawing::Size(353, 30);
    this->tableLayoutPanel3->TabIndex = 13;
    //
    // tableOrderTotalPrice
    //
    this->tableOrderTotalPrice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->tableOrderTotalPrice->AutoSize = true;
    this->tableOrderTotalPrice->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->tableOrderTotalPrice->ForeColor = System::Drawing::SystemColors::ButtonFace;
    this->tableOrderTotalPrice->Location = System::Drawing::Point(266, 0);
    this->tableOrderTotalPrice->Name = L"tableOrderTotalPrice";
    this->tableOrderTotalPrice->Size = System::Drawing::Size(84, 30);
    this->tableOrderTotalPrice->TabIndex = 1;
    this->tableOrderTotalPrice->Text = L"0";
    this->tableOrderTotalPrice->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // tableOrderTotalName
    //
    this->tableOrderTotalName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->tableOrderTotalName->AutoSize = true;
    this->tableOrderTotalName->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->tableOrderTotalName->ForeColor = System::Drawing::SystemColors::ButtonFace;
    this->tableOrderTotalName->Location = System::Drawing::Point(3, 0);
    this->tableOrderTotalName->Name = L"tableOrderTotalName";
    this->tableOrderTotalName->Size = System::Drawing::Size(257, 30);
    this->tableOrderTotalName->TabIndex = 0;
    this->tableOrderTotalName->Text = L"Total";
    this->tableOrderTotalName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // tableOrderLayoutPanel
    //
    this->tableOrderLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
         System::Windows::Forms::AnchorStyles::Left));
    this->tableOrderLayoutPanel->AutoScroll = true;
    this->tableOrderLayoutPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(19)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(61)));
    this->tableOrderLayoutPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Outset;
    this->tableOrderLayoutPanel->ColumnCount = 2;
    this->tableOrderLayoutPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 74.76636F)));
    this->tableOrderLayoutPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25.23364F)));
    this->tableOrderLayoutPanel->Location = System::Drawing::Point(5, 36);
    this->tableOrderLayoutPanel->Name = L"tableOrderLayoutPanel";
    this->tableOrderLayoutPanel->RowCount = 1;
    this->tableOrderLayoutPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
    this->tableOrderLayoutPanel->Size = System::Drawing::Size(353, 209);
    this->tableOrderLayoutPanel->TabIndex = 11;
    //
    // tableOrderPayButton
    //
    this->tableOrderPayButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
    this->tableOrderPayButton->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->tableOrderPayButton->ForeColor = System::Drawing::Color::LimeGreen;
    this->tableOrderPayButton->Location = System::Drawing::Point(-9, 287);
    this->tableOrderPayButton->Name = L"tableOrderPayButton";
    this->tableOrderPayButton->Size = System::Drawing::Size(369, 50);
    this->tableOrderPayButton->TabIndex = 10;
    this->tableOrderPayButton->Text = L"Pay";
    this->tableOrderPayButton->UseVisualStyleBackColor = true;
    this->tableOrderPayButton->Click += gcnew System::EventHandler(this, &Main::tableOrderPayButton_Click);
    //
    // orderPanel
    //
    this->orderPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
         System::Windows::Forms::AnchorStyles::Left));
    this->orderPanel->Controls->Add(this->orderPanelFooterTotalString);
    this->orderPanel->Controls->Add(this->orderPanelFooter);
    this->orderPanel->Controls->Add(this->eatoutOrderLayoutPanelTableLabel);
    this->orderPanel->Controls->Add(this->clearOrderLayoutPanelTableLabel);
    this->orderPanel->Controls->Add(this->eatinOrderLayoutPanelTableLabel);
    this->orderPanel->Controls->Add(this->orderLayoutPanel);
    this->orderPanel->Controls->Add(this->confirmOrderLayoutPanelTableLabel);
    this->orderPanel->Location = System::Drawing::Point(5, 280);
    this->orderPanel->Name = L"orderPanel";
    this->orderPanel->Size = System::Drawing::Size(384, 337);
    this->orderPanel->TabIndex = 8;
    //
    // orderPanelFooterTotalString
    //
    this->orderPanelFooterTotalString->ColumnCount = 2;
    this->orderPanelFooterTotalString->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 75.49857F)));
    this->orderPanelFooterTotalString->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 24.50142F)));
    this->orderPanelFooterTotalString->Controls->Add(this->label2, 1, 0);
    this->orderPanelFooterTotalString->Controls->Add(this->label1, 0, 0);
    this->orderPanelFooterTotalString->Location = System::Drawing::Point(5, 3);
    this->orderPanelFooterTotalString->Name = L"orderPanelFooterTotalString";
    this->orderPanelFooterTotalString->RowCount = 1;
    this->orderPanelFooterTotalString->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
    this->orderPanelFooterTotalString->Size = System::Drawing::Size(353, 30);
    this->orderPanelFooterTotalString->TabIndex = 15;
    //
    // label2
    //
    this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->label2->AutoSize = true;
    this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
    this->label2->Location = System::Drawing::Point(269, 0);
    this->label2->Name = L"label2";
    this->label2->Size = System::Drawing::Size(81, 30);
    this->label2->TabIndex = 1;
    this->label2->Text = L"Price";
    this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // label1
    //
    this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->label1->AutoSize = true;
    this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
    this->label1->Location = System::Drawing::Point(3, 0);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(260, 30);
    this->label1->TabIndex = 0;
    this->label1->Text = L"Item";
    this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // orderPanelFooter
    //
    this->orderPanelFooter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->orderPanelFooter->ColumnCount = 2;
    this->orderPanelFooter->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 74.66307F)));
    this->orderPanelFooter->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25.33693F)));
    this->orderPanelFooter->Controls->Add(this->orderPanelFooterTotalInt, 1, 0);
    this->orderPanelFooter->Controls->Add(this->orderPanelFooterT, 0, 0);
    this->orderPanelFooter->Location = System::Drawing::Point(5, 247);
    this->orderPanelFooter->Name = L"orderPanelFooter";
    this->orderPanelFooter->RowCount = 1;
    this->orderPanelFooter->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
    this->orderPanelFooter->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
    this->orderPanelFooter->Size = System::Drawing::Size(353, 30);
    this->orderPanelFooter->TabIndex = 13;
    //
    // orderPanelFooterTotalInt
    //
    this->orderPanelFooterTotalInt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->orderPanelFooterTotalInt->AutoSize = true;
    this->orderPanelFooterTotalInt->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->orderPanelFooterTotalInt->ForeColor = System::Drawing::SystemColors::ButtonFace;
    this->orderPanelFooterTotalInt->Location = System::Drawing::Point(266, 0);
    this->orderPanelFooterTotalInt->Name = L"orderPanelFooterTotalInt";
    this->orderPanelFooterTotalInt->Size = System::Drawing::Size(84, 30);
    this->orderPanelFooterTotalInt->TabIndex = 1;
    this->orderPanelFooterTotalInt->Text = L"0";
    this->orderPanelFooterTotalInt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // orderPanelFooterT
    //
    this->orderPanelFooterT->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->orderPanelFooterT->AutoSize = true;
    this->orderPanelFooterT->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->orderPanelFooterT->ForeColor = System::Drawing::SystemColors::ButtonFace;
    this->orderPanelFooterT->Location = System::Drawing::Point(3, 0);
    this->orderPanelFooterT->Name = L"orderPanelFooterT";
    this->orderPanelFooterT->Size = System::Drawing::Size(257, 30);
    this->orderPanelFooterT->TabIndex = 0;
    this->orderPanelFooterT->Text = L"Total";
    this->orderPanelFooterT->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // eatoutOrderLayoutPanelTableLabel
    //
    this->eatoutOrderLayoutPanelTableLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
    this->eatoutOrderLayoutPanelTableLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->eatoutOrderLayoutPanelTableLabel->ForeColor = System::Drawing::Color::Black;
    this->eatoutOrderLayoutPanelTableLabel->Location = System::Drawing::Point(191, 283);
    this->eatoutOrderLayoutPanelTableLabel->Name = L"eatoutOrderLayoutPanelTableLabel";
    this->eatoutOrderLayoutPanelTableLabel->Size = System::Drawing::Size(190, 50);
    this->eatoutOrderLayoutPanelTableLabel->TabIndex = 17;
    this->eatoutOrderLayoutPanelTableLabel->Text = L"Take away";
    this->eatoutOrderLayoutPanelTableLabel->UseVisualStyleBackColor = true;
    this->eatoutOrderLayoutPanelTableLabel->Visible = false;
    //
    // clearOrderLayoutPanelTableLabel
    //
    this->clearOrderLayoutPanelTableLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
    this->clearOrderLayoutPanelTableLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->clearOrderLayoutPanelTableLabel->ForeColor = System::Drawing::Color::Red;
    this->clearOrderLayoutPanelTableLabel->Location = System::Drawing::Point(183, 283);
    this->clearOrderLayoutPanelTableLabel->Name = L"clearOrderLayoutPanelTableLabel";
    this->clearOrderLayoutPanelTableLabel->Size = System::Drawing::Size(190, 50);
    this->clearOrderLayoutPanelTableLabel->TabIndex = 14;
    this->clearOrderLayoutPanelTableLabel->Text = L"Clear order";
    this->clearOrderLayoutPanelTableLabel->UseVisualStyleBackColor = true;
    //
    // eatinOrderLayoutPanelTableLabel
    //
    this->eatinOrderLayoutPanelTableLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
    this->eatinOrderLayoutPanelTableLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->eatinOrderLayoutPanelTableLabel->ForeColor = System::Drawing::Color::Black;
    this->eatinOrderLayoutPanelTableLabel->Location = System::Drawing::Point(-1, 283);
    this->eatinOrderLayoutPanelTableLabel->Name = L"eatinOrderLayoutPanelTableLabel";
    this->eatinOrderLayoutPanelTableLabel->Size = System::Drawing::Size(190, 50);
    this->eatinOrderLayoutPanelTableLabel->TabIndex = 16;
    this->eatinOrderLayoutPanelTableLabel->Text = L"Eat in";
    this->eatinOrderLayoutPanelTableLabel->UseVisualStyleBackColor = true;
    this->eatinOrderLayoutPanelTableLabel->Visible = false;
    this->eatinOrderLayoutPanelTableLabel->Click +=
        gcnew System::EventHandler(this, &Main::eatinOrderLayoutPanelTableLabel_Click);
    //
    // orderLayoutPanel
    //
    this->orderLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
         System::Windows::Forms::AnchorStyles::Left));
    this->orderLayoutPanel->AutoScroll = true;
    this->orderLayoutPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(19)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(61)));
    this->orderLayoutPanel->ColumnCount = 2;
    this->orderLayoutPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 74.76636F)));
    this->orderLayoutPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25.23364F)));
    this->orderLayoutPanel->Location = System::Drawing::Point(5, 36);
    this->orderLayoutPanel->Name = L"orderLayoutPanel";
    this->orderLayoutPanel->RowCount = 2;
    this->orderLayoutPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
    this->orderLayoutPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
    this->orderLayoutPanel->Size = System::Drawing::Size(353, 205);
    this->orderLayoutPanel->TabIndex = 11;
    //
    // confirmOrderLayoutPanelTableLabel
    //
    this->confirmOrderLayoutPanelTableLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
    this->confirmOrderLayoutPanelTableLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold));
    this->confirmOrderLayoutPanelTableLabel->ForeColor = System::Drawing::Color::LimeGreen;
    this->confirmOrderLayoutPanelTableLabel->Location = System::Drawing::Point(-11, 283);
    this->confirmOrderLayoutPanelTableLabel->Name = L"confirmOrderLayoutPanelTableLabel";
    this->confirmOrderLayoutPanelTableLabel->Size = System::Drawing::Size(190, 50);
    this->confirmOrderLayoutPanelTableLabel->TabIndex = 10;
    this->confirmOrderLayoutPanelTableLabel->Text = L"Confirm order";
    this->confirmOrderLayoutPanelTableLabel->UseVisualStyleBackColor = true;
    this->confirmOrderLayoutPanelTableLabel->Click +=
        gcnew System::EventHandler(this, &Main::confirmOrderLayoutPanelTableLabel_Click);
    //
    // navigationPanel
    //
    this->navigationPanel->Controls->Add(this->tablesButton);
    this->navigationPanel->Controls->Add(this->adminButton);
    this->navigationPanel->Controls->Add(this->clockButton);
    this->navigationPanel->Controls->Add(this->dessertButton);
    this->navigationPanel->Controls->Add(this->mainButton);
    this->navigationPanel->Controls->Add(this->entreeButton);
    this->navigationPanel->Controls->Add(this->drinkButton);
    this->navigationPanel->Dock = System::Windows::Forms::DockStyle::Top;
    this->navigationPanel->Location = System::Drawing::Point(0, 100);
    this->navigationPanel->Name = L"navigationPanel";
    this->navigationPanel->Size = System::Drawing::Size(392, 174);
    this->navigationPanel->TabIndex = 9;
    //
    // tablesButton
    //
    this->tablesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->tablesButton->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"tablesButton.Image")));
    this->tablesButton->Location = System::Drawing::Point(1, 8);
    this->tablesButton->Name = L"tablesButton";
    this->tablesButton->Size = System::Drawing::Size(77, 67);
    this->tablesButton->TabIndex = 13;
    this->tablesButton->UseVisualStyleBackColor = true;
    this->tablesButton->Click += gcnew System::EventHandler(this, &Main::tablesButton_Click);
    //
    // adminButton
    //
    this->adminButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->adminButton->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"adminButton.Image")));
    this->adminButton->Location = System::Drawing::Point(104, 8);
    this->adminButton->Name = L"adminButton";
    this->adminButton->Size = System::Drawing::Size(77, 67);
    this->adminButton->TabIndex = 12;
    this->adminButton->UseVisualStyleBackColor = true;
    this->adminButton->Click += gcnew System::EventHandler(this, &Main::adminButton_Click);
    //
    // clockButton
    //
    this->clockButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->clockButton->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"clockButton.Image")));
    this->clockButton->Location = System::Drawing::Point(207, 8);
    this->clockButton->Name = L"clockButton";
    this->clockButton->Size = System::Drawing::Size(77, 67);
    this->clockButton->TabIndex = 11;
    this->clockButton->UseVisualStyleBackColor = true;
    this->clockButton->Click += gcnew System::EventHandler(this, &Main::clockButton_Click);
    //
    // dessertButton
    //
    this->dessertButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->dessertButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"dessertButton.Image")));
    this->dessertButton->Location = System::Drawing::Point(310, 102);
    this->dessertButton->Name = L"dessertButton";
    this->dessertButton->Size = System::Drawing::Size(77, 67);
    this->dessertButton->TabIndex = 10;
    this->dessertButton->UseVisualStyleBackColor = true;
    this->dessertButton->Click += gcnew System::EventHandler(this, &Main::dessertButton_Click);
    //
    // mainButton
    //
    this->mainButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->mainButton->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"mainButton.Image")));
    this->mainButton->Location = System::Drawing::Point(207, 102);
    this->mainButton->Name = L"mainButton";
    this->mainButton->Size = System::Drawing::Size(77, 67);
    this->mainButton->TabIndex = 9;
    this->mainButton->UseVisualStyleBackColor = true;
    this->mainButton->Click += gcnew System::EventHandler(this, &Main::mainButton_Click);
    //
    // entreeButton
    //
    this->entreeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->entreeButton->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"entreeButton.Image")));
    this->entreeButton->Location = System::Drawing::Point(104, 102);
    this->entreeButton->Name = L"entreeButton";
    this->entreeButton->Size = System::Drawing::Size(77, 67);
    this->entreeButton->TabIndex = 8;
    this->entreeButton->UseVisualStyleBackColor = true;
    this->entreeButton->Click += gcnew System::EventHandler(this, &Main::entreeButton_Click);
    //
    // drinkButton
    //
    this->drinkButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->drinkButton->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"drinkButton.Image")));
    this->drinkButton->Location = System::Drawing::Point(1, 102);
    this->drinkButton->Name = L"drinkButton";
    this->drinkButton->Size = System::Drawing::Size(77, 67);
    this->drinkButton->TabIndex = 7;
    this->drinkButton->UseVisualStyleBackColor = true;
    this->drinkButton->Click += gcnew System::EventHandler(this, &Main::drinkButton_Click);
    //
    // sidePanelHeaderPanel
    //
    this->sidePanelHeaderPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(19)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(61)));
    this->sidePanelHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->sidePanelHeaderPanel->Controls->Add(this->headerSoftwareNameLabel);
    this->sidePanelHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
    this->sidePanelHeaderPanel->Location = System::Drawing::Point(0, 0);
    this->sidePanelHeaderPanel->Name = L"sidePanelHeaderPanel";
    this->sidePanelHeaderPanel->Size = System::Drawing::Size(392, 100);
    this->sidePanelHeaderPanel->TabIndex = 7;
    //
    // headerSoftwareNameLabel
    //
    this->headerSoftwareNameLabel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(19)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(61)));
    this->headerSoftwareNameLabel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->headerSoftwareNameLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Black", 48, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->headerSoftwareNameLabel->ForeColor = System::Drawing::SystemColors::ControlLight;
    this->headerSoftwareNameLabel->Location = System::Drawing::Point(0, 0);
    this->headerSoftwareNameLabel->Name = L"headerSoftwareNameLabel";
    this->headerSoftwareNameLabel->RightToLeft = System::Windows::Forms::RightToLeft::No;
    this->headerSoftwareNameLabel->Size = System::Drawing::Size(388, 96);
    this->headerSoftwareNameLabel->TabIndex = 0;
    this->headerSoftwareNameLabel->Text = L"RMSPOS";
    this->headerSoftwareNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // adminPanel
    //
    this->adminPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->adminPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->adminPanel->Controls->Add(this->removePanel);
    this->adminPanel->Controls->Add(this->contactPanel);
    this->adminPanel->Controls->Add(this->addPanel);
    this->adminPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->adminPanel->Location = System::Drawing::Point(396, 102);
    this->adminPanel->Name = L"adminPanel";
    this->adminPanel->Size = System::Drawing::Size(904, 625);
    this->adminPanel->TabIndex = 13;
    this->adminPanel->Visible = false;
    //
    // removePanel
    //
    this->removePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
         System::Windows::Forms::AnchorStyles::Left));
    this->removePanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->removePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->removePanel->Controls->Add(this->button2);
    this->removePanel->Controls->Add(this->removeManagerButton);
    this->removePanel->Controls->Add(this->removeWaiterButton);
    this->removePanel->Controls->Add(this->removeMenuItemButton);
    this->removePanel->Controls->Add(this->Remove);
    this->removePanel->Location = System::Drawing::Point(515, 0);
    this->removePanel->Name = L"removePanel";
    this->removePanel->Size = System::Drawing::Size(257, 621);
    this->removePanel->TabIndex = 9;
    //
    // button2
    //
    this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->button2->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"button2.Image")));
    this->button2->Location = System::Drawing::Point(15, 191);
    this->button2->Name = L"button2";
    this->button2->Size = System::Drawing::Size(77, 81);
    this->button2->TabIndex = 12;
    this->button2->UseVisualStyleBackColor = true;
    //
    // removeManagerButton
    //
    this->removeManagerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->removeManagerButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"removeManagerButton.Image")));
    this->removeManagerButton->Location = System::Drawing::Point(15, 280);
    this->removeManagerButton->Name = L"removeManagerButton";
    this->removeManagerButton->Size = System::Drawing::Size(77, 81);
    this->removeManagerButton->TabIndex = 11;
    this->removeManagerButton->UseVisualStyleBackColor = true;
    //
    // removeWaiterButton
    //
    this->removeWaiterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->removeWaiterButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"removeWaiterButton.Image")));
    this->removeWaiterButton->Location = System::Drawing::Point(141, 280);
    this->removeWaiterButton->Name = L"removeWaiterButton";
    this->removeWaiterButton->Size = System::Drawing::Size(77, 81);
    this->removeWaiterButton->TabIndex = 10;
    this->removeWaiterButton->UseVisualStyleBackColor = true;
    //
    // removeMenuItemButton
    //
    this->removeMenuItemButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->removeMenuItemButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"removeMenuItemButton.Image")));
    this->removeMenuItemButton->Location = System::Drawing::Point(141, 191);
    this->removeMenuItemButton->Name = L"removeMenuItemButton";
    this->removeMenuItemButton->Size = System::Drawing::Size(77, 81);
    this->removeMenuItemButton->TabIndex = 9;
    this->removeMenuItemButton->UseVisualStyleBackColor = true;
    //
    // Remove
    //
    this->Remove->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"Remove.Image")));
    this->Remove->Location = System::Drawing::Point(66, 0);
    this->Remove->Name = L"Remove";
    this->Remove->Size = System::Drawing::Size(128, 128);
    this->Remove->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
    this->Remove->TabIndex = 3;
    this->Remove->TabStop = false;
    //
    // contactPanel
    //
    this->contactPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
         System::Windows::Forms::AnchorStyles::Left));
    this->contactPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->contactPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->contactPanel->Controls->Add(this->Contact);
    this->contactPanel->Controls->Add(this->orderSuppliesButton);
    this->contactPanel->Location = System::Drawing::Point(258, 0);
    this->contactPanel->Name = L"contactPanel";
    this->contactPanel->Size = System::Drawing::Size(257, 621);
    this->contactPanel->TabIndex = 10;
    //
    // Contact
    //
    this->Contact->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"Contact.Image")));
    this->Contact->Location = System::Drawing::Point(66, 0);
    this->Contact->Name = L"Contact";
    this->Contact->Size = System::Drawing::Size(128, 128);
    this->Contact->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
    this->Contact->TabIndex = 3;
    this->Contact->TabStop = false;
    //
    // orderSuppliesButton
    //
    this->orderSuppliesButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"orderSuppliesButton.Image")));
    this->orderSuppliesButton->Location = System::Drawing::Point(18, 191);
    this->orderSuppliesButton->Name = L"orderSuppliesButton";
    this->orderSuppliesButton->Size = System::Drawing::Size(77, 81);
    this->orderSuppliesButton->TabIndex = 1;
    this->orderSuppliesButton->UseVisualStyleBackColor = true;
    //
    // addPanel
    //
    this->addPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
         System::Windows::Forms::AnchorStyles::Left));
    this->addPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->addPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->addPanel->Controls->Add(this->addNewTableButton);
    this->addPanel->Controls->Add(this->addManagerButton);
    this->addPanel->Controls->Add(this->addWaiterButton);
    this->addPanel->Controls->Add(this->addMenuItemButton);
    this->addPanel->Controls->Add(this->Add);
    this->addPanel->Location = System::Drawing::Point(0, 0);
    this->addPanel->Name = L"addPanel";
    this->addPanel->Size = System::Drawing::Size(257, 621);
    this->addPanel->TabIndex = 8;
    //
    // addNewTableButton
    //
    this->addNewTableButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->addNewTableButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"addNewTableButton.Image")));
    this->addNewTableButton->Location = System::Drawing::Point(22, 191);
    this->addNewTableButton->Name = L"addNewTableButton";
    this->addNewTableButton->Size = System::Drawing::Size(77, 81);
    this->addNewTableButton->TabIndex = 10;
    this->addNewTableButton->UseVisualStyleBackColor = true;
    this->addNewTableButton->Click += gcnew System::EventHandler(this, &Main::addNewTableButton_Click);
    //
    // addManagerButton
    //
    this->addManagerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->addManagerButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"addManagerButton.Image")));
    this->addManagerButton->Location = System::Drawing::Point(22, 280);
    this->addManagerButton->Name = L"addManagerButton";
    this->addManagerButton->Size = System::Drawing::Size(77, 81);
    this->addManagerButton->TabIndex = 9;
    this->addManagerButton->UseVisualStyleBackColor = true;
    this->addManagerButton->Click += gcnew System::EventHandler(this, &Main::addManagerButton_Click);
    //
    // addWaiterButton
    //
    this->addWaiterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->addWaiterButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"addWaiterButton.Image")));
    this->addWaiterButton->Location = System::Drawing::Point(146, 285);
    this->addWaiterButton->Name = L"addWaiterButton";
    this->addWaiterButton->Size = System::Drawing::Size(77, 81);
    this->addWaiterButton->TabIndex = 8;
    this->addWaiterButton->UseVisualStyleBackColor = true;
    this->addWaiterButton->Click += gcnew System::EventHandler(this, &Main::addWaiterButton_Click);
    //
    // addMenuItemButton
    //
    this->addMenuItemButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->addMenuItemButton->Image =
        (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"addMenuItemButton.Image")));
    this->addMenuItemButton->Location = System::Drawing::Point(146, 191);
    this->addMenuItemButton->Name = L"addMenuItemButton";
    this->addMenuItemButton->Size = System::Drawing::Size(77, 81);
    this->addMenuItemButton->TabIndex = 7;
    this->addMenuItemButton->UseVisualStyleBackColor = true;
    this->addMenuItemButton->Click += gcnew System::EventHandler(this, &Main::addMenuItemButton_Click);
    //
    // Add
    //
    this->Add->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"Add.Image")));
    this->Add->Location = System::Drawing::Point(66, 0);
    this->Add->Name = L"Add";
    this->Add->Size = System::Drawing::Size(128, 128);
    this->Add->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
    this->Add->TabIndex = 3;
    this->Add->TabStop = false;
    //
    // headerPanel
    //
    this->headerPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(6)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(66)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(122)));
    this->headerPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->headerPanel->Controls->Add(this->headerNavigationLabel);
    this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
    this->headerPanel->Location = System::Drawing::Point(0, 0);
    this->headerPanel->Name = L"headerPanel";
    this->headerPanel->Size = System::Drawing::Size(1300, 102);
    this->headerPanel->TabIndex = 0;
    //
    // headerNavigationLabel
    //
    this->headerNavigationLabel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(19)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(61)));
    this->headerNavigationLabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->headerNavigationLabel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->headerNavigationLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 27.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->headerNavigationLabel->ForeColor = System::Drawing::SystemColors::ControlLight;
    this->headerNavigationLabel->Location = System::Drawing::Point(0, 0);
    this->headerNavigationLabel->Name = L"headerNavigationLabel";
    this->headerNavigationLabel->Size = System::Drawing::Size(1298, 100);
    this->headerNavigationLabel->TabIndex = 1;
    this->headerNavigationLabel->Text = L"Tables";
    this->headerNavigationLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    //
    // clockinPanel
    //
    this->clockinPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->clockinPanel->Controls->Add(this->clockinFailedLabel);
    this->clockinPanel->Controls->Add(this->staffpasswordrichTextBox);
    this->clockinPanel->Controls->Add(this->clockOutbutton);
    this->clockinPanel->Controls->Add(this->clockinButton);
    this->clockinPanel->Controls->Add(this->staffpasswordLabel);
    this->clockinPanel->Controls->Add(this->staffnumberLabel);
    this->clockinPanel->Controls->Add(this->staffnumberrichTextBox);
    this->clockinPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->clockinPanel->Location = System::Drawing::Point(396, 102);
    this->clockinPanel->Name = L"clockinPanel";
    this->clockinPanel->Size = System::Drawing::Size(904, 625);
    this->clockinPanel->TabIndex = 3;
    this->clockinPanel->Visible = false;
    //
    // clockinFailedLabel
    //
    this->clockinFailedLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->clockinFailedLabel->AutoSize = true;
    this->clockinFailedLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->clockinFailedLabel->ForeColor = System::Drawing::Color::Red;
    this->clockinFailedLabel->Location = System::Drawing::Point(295, 475);
    this->clockinFailedLabel->Name = L"clockinFailedLabel";
    this->clockinFailedLabel->Size = System::Drawing::Size(315, 37);
    this->clockinFailedLabel->TabIndex = 7;
    this->clockinFailedLabel->Text = L"Initials or ID is incorrect";
    this->clockinFailedLabel->Visible = false;
    //
    // staffpasswordrichTextBox
    //
    this->staffpasswordrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->staffpasswordrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->staffpasswordrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->staffpasswordrichTextBox->Location = System::Drawing::Point(367, 255);
    this->staffpasswordrichTextBox->MaxLength = 10;
    this->staffpasswordrichTextBox->Name = L"staffpasswordrichTextBox";
    this->staffpasswordrichTextBox->Size = System::Drawing::Size(180, 48);
    this->staffpasswordrichTextBox->TabIndex = 6;
    this->staffpasswordrichTextBox->Text = L"";
    //
    // clockOutbutton
    //
    this->clockOutbutton->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->clockOutbutton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->clockOutbutton->ForeColor = System::Drawing::Color::Crimson;
    this->clockOutbutton->Location = System::Drawing::Point(385, 378);
    this->clockOutbutton->Name = L"clockOutbutton";
    this->clockOutbutton->Size = System::Drawing::Size(151, 45);
    this->clockOutbutton->TabIndex = 5;
    this->clockOutbutton->Text = L"Clock out";
    this->clockOutbutton->UseVisualStyleBackColor = true;
    this->clockOutbutton->Click += gcnew System::EventHandler(this, &Main::clockOutbutton_Click);
    //
    // clockinButton
    //
    this->clockinButton->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->clockinButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->clockinButton->ForeColor = System::Drawing::Color::DodgerBlue;
    this->clockinButton->Location = System::Drawing::Point(385, 318);
    this->clockinButton->Name = L"clockinButton";
    this->clockinButton->Size = System::Drawing::Size(151, 45);
    this->clockinButton->TabIndex = 4;
    this->clockinButton->Text = L"Clock in";
    this->clockinButton->UseVisualStyleBackColor = true;
    this->clockinButton->Click += gcnew System::EventHandler(this, &Main::clockinButton_Click);
    //
    // staffpasswordLabel
    //
    this->staffpasswordLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->staffpasswordLabel->AutoSize = true;
    this->staffpasswordLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->staffpasswordLabel->Location = System::Drawing::Point(395, 215);
    this->staffpasswordLabel->Name = L"staffpasswordLabel";
    this->staffpasswordLabel->Size = System::Drawing::Size(110, 37);
    this->staffpasswordLabel->TabIndex = 1;
    this->staffpasswordLabel->Text = L"Staff ID";
    //
    // staffnumberLabel
    //
    this->staffnumberLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->staffnumberLabel->AutoSize = true;
    this->staffnumberLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->staffnumberLabel->Location = System::Drawing::Point(367, 112);
    this->staffnumberLabel->Name = L"staffnumberLabel";
    this->staffnumberLabel->Size = System::Drawing::Size(167, 37);
    this->staffnumberLabel->TabIndex = 0;
    this->staffnumberLabel->Text = L"Staff Initials";
    //
    // staffnumberrichTextBox
    //
    this->staffnumberrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->staffnumberrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->staffnumberrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->staffnumberrichTextBox->Location = System::Drawing::Point(367, 164);
    this->staffnumberrichTextBox->MaxLength = 10;
    this->staffnumberrichTextBox->Name = L"staffnumberrichTextBox";
    this->staffnumberrichTextBox->Size = System::Drawing::Size(180, 48);
    this->staffnumberrichTextBox->TabIndex = 2;
    this->staffnumberrichTextBox->Text = L"";
    //
    // adminLoginPanel
    //
    this->adminLoginPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->adminLoginPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->adminLoginPanel->Controls->Add(this->loginFailedLabel);
    this->adminLoginPanel->Controls->Add(this->adminPasswordrichTextBox);
    this->adminLoginPanel->Controls->Add(this->LoginButton);
    this->adminLoginPanel->Controls->Add(this->adminPasswordLabel);
    this->adminLoginPanel->Controls->Add(this->adminNumberLabel);
    this->adminLoginPanel->Controls->Add(this->adminNumberrichTextBox);
    this->adminLoginPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->adminLoginPanel->Location = System::Drawing::Point(0, 102);
    this->adminLoginPanel->Name = L"adminLoginPanel";
    this->adminLoginPanel->Size = System::Drawing::Size(1300, 625);
    this->adminLoginPanel->TabIndex = 7;
    this->adminLoginPanel->Visible = false;
    //
    // loginFailedLabel
    //
    this->loginFailedLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->loginFailedLabel->AutoSize = true;
    this->loginFailedLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->loginFailedLabel->ForeColor = System::Drawing::Color::Red;
    this->loginFailedLabel->Location = System::Drawing::Point(419, 430);
    this->loginFailedLabel->Name = L"loginFailedLabel";
    this->loginFailedLabel->Size = System::Drawing::Size(457, 37);
    this->loginFailedLabel->TabIndex = 13;
    this->loginFailedLabel->Text = L"Username or password is incorrect";
    this->loginFailedLabel->Visible = false;
    //
    // adminPasswordrichTextBox
    //
    this->adminPasswordrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->adminPasswordrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->adminPasswordrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->adminPasswordrichTextBox->Location = System::Drawing::Point(561, 297);
    this->adminPasswordrichTextBox->MaxLength = 10;
    this->adminPasswordrichTextBox->Name = L"adminPasswordrichTextBox";
    this->adminPasswordrichTextBox->Size = System::Drawing::Size(180, 48);
    this->adminPasswordrichTextBox->TabIndex = 12;
    this->adminPasswordrichTextBox->Text = L"";
    //
    // LoginButton
    //
    this->LoginButton->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->LoginButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->LoginButton->ForeColor = System::Drawing::Color::DodgerBlue;
    this->LoginButton->Location = System::Drawing::Point(579, 360);
    this->LoginButton->Name = L"LoginButton";
    this->LoginButton->Size = System::Drawing::Size(151, 45);
    this->LoginButton->TabIndex = 10;
    this->LoginButton->Text = L"Log in";
    this->LoginButton->UseVisualStyleBackColor = true;
    this->LoginButton->Click += gcnew System::EventHandler(this, &Main::LoginButton_Click);
    //
    // adminPasswordLabel
    //
    this->adminPasswordLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->adminPasswordLabel->AutoSize = true;
    this->adminPasswordLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->adminPasswordLabel->Location = System::Drawing::Point(554, 257);
    this->adminPasswordLabel->Name = L"adminPasswordLabel";
    this->adminPasswordLabel->Size = System::Drawing::Size(230, 37);
    this->adminPasswordLabel->TabIndex = 8;
    this->adminPasswordLabel->Text = L"Admin Password";
    //
    // adminNumberLabel
    //
    this->adminNumberLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->adminNumberLabel->AutoSize = true;
    this->adminNumberLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->adminNumberLabel->Location = System::Drawing::Point(561, 154);
    this->adminNumberLabel->Name = L"adminNumberLabel";
    this->adminNumberLabel->Size = System::Drawing::Size(201, 37);
    this->adminNumberLabel->TabIndex = 7;
    this->adminNumberLabel->Text = L"Admin number";
    //
    // adminNumberrichTextBox
    //
    this->adminNumberrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->adminNumberrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->adminNumberrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->adminNumberrichTextBox->Location = System::Drawing::Point(561, 206);
    this->adminNumberrichTextBox->MaxLength = 10;
    this->adminNumberrichTextBox->Name = L"adminNumberrichTextBox";
    this->adminNumberrichTextBox->Size = System::Drawing::Size(180, 48);
    this->adminNumberrichTextBox->TabIndex = 9;
    this->adminNumberrichTextBox->Text = L"";
    //
    // drinksMenuPanel
    //
    this->drinksMenuPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->drinksMenuPanel->ColumnCount = 9;
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->drinksMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 684)));
    this->drinksMenuPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->drinksMenuPanel->Location = System::Drawing::Point(396, 102);
    this->drinksMenuPanel->Name = L"drinksMenuPanel";
    this->drinksMenuPanel->RowCount = 9;
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->drinksMenuPanel->Size = System::Drawing::Size(904, 625);
    this->drinksMenuPanel->TabIndex = 0;
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
    this->addItemPanel->Location = System::Drawing::Point(0, 0);
    this->addItemPanel->Name = L"addItemPanel";
    this->addItemPanel->Size = System::Drawing::Size(1300, 782);
    this->addItemPanel->TabIndex = 8;
    this->addItemPanel->Visible = false;
    //
    // errorLabel
    //
    this->errorLabel->AutoSize = true;
    this->errorLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->errorLabel->ForeColor = System::Drawing::Color::Red;
    this->errorLabel->Location = System::Drawing::Point(256, 497);
    this->errorLabel->Name = L"errorLabel";
    this->errorLabel->Size = System::Drawing::Size(515, 25);
    this->errorLabel->TabIndex = 21;
    this->errorLabel->Text = L"Please first choose item category from the dropdown menu";
    this->errorLabel->Visible = false;
    //
    // itemCategory
    //
    this->itemCategory->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->itemCategory->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->itemCategory->FormattingEnabled = true;
    this->itemCategory->Items->AddRange(
        gcnew cli::array<System::Object ^>(4){L"Drink", L"Entree", L"Main", L"Dessert"});
    this->itemCategory->Location = System::Drawing::Point(423, 420);
    this->itemCategory->Name = L"itemCategory";
    this->itemCategory->Size = System::Drawing::Size(180, 45);
    this->itemCategory->TabIndex = 20;
    //
    // addDrinkButton
    //
    this->addDrinkButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->addDrinkButton->ForeColor = System::Drawing::Color::DodgerBlue;
    this->addDrinkButton->Location = System::Drawing::Point(423, 554);
    this->addDrinkButton->Name = L"addDrinkButton";
    this->addDrinkButton->Size = System::Drawing::Size(180, 45);
    this->addDrinkButton->TabIndex = 19;
    this->addDrinkButton->Text = L"Add";
    this->addDrinkButton->UseVisualStyleBackColor = true;
    this->addDrinkButton->Click += gcnew System::EventHandler(this, &Main::addDrinkButton_Click);
    //
    // itemPricerichTextBox
    //
    this->itemPricerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->itemPricerichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
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
    this->itemPriceLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
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
    this->itemNameLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->itemNameLabel->Location = System::Drawing::Point(432, 213);
    this->itemNameLabel->Name = L"itemNameLabel";
    this->itemNameLabel->Size = System::Drawing::Size(150, 37);
    this->itemNameLabel->TabIndex = 13;
    this->itemNameLabel->Text = L"Item Name";
    //
    // itemNamerichTextBox
    //
    this->itemNamerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->itemNamerichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->itemNamerichTextBox->Location = System::Drawing::Point(423, 265);
    this->itemNamerichTextBox->MaxLength = 10;
    this->itemNamerichTextBox->Name = L"itemNamerichTextBox";
    this->itemNamerichTextBox->Size = System::Drawing::Size(180, 48);
    this->itemNamerichTextBox->TabIndex = 15;
    this->itemNamerichTextBox->Text = L"";
    //
    // entreeMenuPanel
    //
    this->entreeMenuPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->entreeMenuPanel->ColumnCount = 9;
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->entreeMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 684)));
    this->entreeMenuPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->entreeMenuPanel->Location = System::Drawing::Point(396, 102);
    this->entreeMenuPanel->Name = L"entreeMenuPanel";
    this->entreeMenuPanel->RowCount = 9;
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->entreeMenuPanel->Size = System::Drawing::Size(904, 625);
    this->entreeMenuPanel->TabIndex = 4;
    this->entreeMenuPanel->Visible = false;
    //
    // mainMenuPanel
    //
    this->mainMenuPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->mainMenuPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->mainMenuPanel->ColumnCount = 9;
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->mainMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 604)));
    this->mainMenuPanel->Location = System::Drawing::Point(403, 102);
    this->mainMenuPanel->Name = L"mainMenuPanel";
    this->mainMenuPanel->RowCount = 9;
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->mainMenuPanel->Size = System::Drawing::Size(897, 625);
    this->mainMenuPanel->TabIndex = 4;
    this->mainMenuPanel->Visible = false;
    //
    // dessertMenuPanel
    //
    this->dessertMenuPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->dessertMenuPanel->ColumnCount = 9;
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 77)));
    this->dessertMenuPanel->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 684)));
    this->dessertMenuPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->dessertMenuPanel->Location = System::Drawing::Point(396, 102);
    this->dessertMenuPanel->Name = L"dessertMenuPanel";
    this->dessertMenuPanel->RowCount = 9;
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 80)));
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 82)));
    this->dessertMenuPanel->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
    this->dessertMenuPanel->Size = System::Drawing::Size(904, 625);
    this->dessertMenuPanel->TabIndex = 5;
    this->dessertMenuPanel->Visible = false;
    //
    // newAdminPanel
    //
    this->newAdminPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->newAdminPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->newAdminPanel->Controls->Add(this->firstnameLabel);
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
    this->newAdminPanel->Controls->Add(this->firstnamerichTextBox);
    this->newAdminPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->newAdminPanel->Location = System::Drawing::Point(0, 102);
    this->newAdminPanel->Name = L"newAdminPanel";
    this->newAdminPanel->Size = System::Drawing::Size(1300, 625);
    this->newAdminPanel->TabIndex = 13;
    this->newAdminPanel->Visible = false;
    //
    // firstnameLabel
    //
    this->firstnameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->firstnameLabel->AutoSize = true;
    this->firstnameLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->firstnameLabel->Location = System::Drawing::Point(218, 96);
    this->firstnameLabel->Name = L"firstnameLabel";
    this->firstnameLabel->Size = System::Drawing::Size(153, 37);
    this->firstnameLabel->TabIndex = 7;
    this->firstnameLabel->Text = L"First Name";
    //
    // salaryLabel
    //
    this->salaryLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->salaryLabel->AutoSize = true;
    this->salaryLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->salaryLabel->Location = System::Drawing::Point(218, 474);
    this->salaryLabel->Name = L"salaryLabel";
    this->salaryLabel->Size = System::Drawing::Size(97, 37);
    this->salaryLabel->TabIndex = 22;
    this->salaryLabel->Text = L"Salary";
    //
    // employmentTypeComboBox
    //
    this->employmentTypeComboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->employmentTypeComboBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->employmentTypeComboBox->FormattingEnabled = true;
    this->employmentTypeComboBox->Items->AddRange(
        gcnew cli::array<System::Object ^>(3){L"Full Time", L"Part Time", L"Casual"});
    this->employmentTypeComboBox->Location = System::Drawing::Point(634, 420);
    this->employmentTypeComboBox->Name = L"employmentTypeComboBox";
    this->employmentTypeComboBox->Size = System::Drawing::Size(121, 45);
    this->employmentTypeComboBox->TabIndex = 21;
    //
    // salaryrichTextBox
    //
    this->salaryrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->salaryrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->salaryrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->salaryrichTextBox->Location = System::Drawing::Point(634, 483);
    this->salaryrichTextBox->MaxLength = 10;
    this->salaryrichTextBox->Name = L"salaryrichTextBox";
    this->salaryrichTextBox->Size = System::Drawing::Size(180, 48);
    this->salaryrichTextBox->TabIndex = 20;
    this->salaryrichTextBox->Text = L"";
    //
    // addressrichTextBox
    //
    this->addressrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->addressrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->addressrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->addressrichTextBox->Location = System::Drawing::Point(634, 354);
    this->addressrichTextBox->MaxLength = 10;
    this->addressrichTextBox->Name = L"addressrichTextBox";
    this->addressrichTextBox->Size = System::Drawing::Size(558, 48);
    this->addressrichTextBox->TabIndex = 19;
    this->addressrichTextBox->Text = L"";
    //
    // agerichTextBox
    //
    this->agerichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->agerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->agerichTextBox->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->agerichTextBox->Location = System::Drawing::Point(634, 288);
    this->agerichTextBox->MaxLength = 10;
    this->agerichTextBox->Name = L"agerichTextBox";
    this->agerichTextBox->Size = System::Drawing::Size(180, 48);
    this->agerichTextBox->TabIndex = 18;
    this->agerichTextBox->Text = L"";
    //
    // genderrichTextBox
    //
    this->genderrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->genderrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->genderrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->genderrichTextBox->Location = System::Drawing::Point(634, 222);
    this->genderrichTextBox->MaxLength = 10;
    this->genderrichTextBox->Name = L"genderrichTextBox";
    this->genderrichTextBox->Size = System::Drawing::Size(180, 48);
    this->genderrichTextBox->TabIndex = 17;
    this->genderrichTextBox->Text = L"";
    //
    // employmenttypeLabel
    //
    this->employmenttypeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->employmenttypeLabel->AutoSize = true;
    this->employmenttypeLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->employmenttypeLabel->Location = System::Drawing::Point(220, 410);
    this->employmenttypeLabel->Name = L"employmenttypeLabel";
    this->employmenttypeLabel->Size = System::Drawing::Size(244, 37);
    this->employmenttypeLabel->TabIndex = 16;
    this->employmenttypeLabel->Text = L"Employment Type";
    //
    // addressLabel
    //
    this->addressLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->addressLabel->AutoSize = true;
    this->addressLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->addressLabel->Location = System::Drawing::Point(220, 346);
    this->addressLabel->Name = L"addressLabel";
    this->addressLabel->Size = System::Drawing::Size(123, 37);
    this->addressLabel->TabIndex = 15;
    this->addressLabel->Text = L"Address";
    //
    // ageLabel
    //
    this->ageLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->ageLabel->AutoSize = true;
    this->ageLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->ageLabel->Location = System::Drawing::Point(220, 282);
    this->ageLabel->Name = L"ageLabel";
    this->ageLabel->Size = System::Drawing::Size(67, 37);
    this->ageLabel->TabIndex = 14;
    this->ageLabel->Text = L"Age";
    //
    // genderLabel
    //
    this->genderLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->genderLabel->AutoSize = true;
    this->genderLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->genderLabel->Location = System::Drawing::Point(220, 218);
    this->genderLabel->Name = L"genderLabel";
    this->genderLabel->Size = System::Drawing::Size(109, 37);
    this->genderLabel->TabIndex = 13;
    this->genderLabel->Text = L"Gender";
    //
    // lastnamerichTextBox
    //
    this->lastnamerichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->lastnamerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->lastnamerichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->lastnamerichTextBox->Location = System::Drawing::Point(634, 156);
    this->lastnamerichTextBox->MaxLength = 10;
    this->lastnamerichTextBox->Name = L"lastnamerichTextBox";
    this->lastnamerichTextBox->Size = System::Drawing::Size(180, 48);
    this->lastnamerichTextBox->TabIndex = 12;
    this->lastnamerichTextBox->Text = L"";
    //
    // createnewadminButton
    //
    this->createnewadminButton->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->createnewadminButton->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->createnewadminButton->ForeColor = System::Drawing::Color::DodgerBlue;
    this->createnewadminButton->Location = System::Drawing::Point(457, 537);
    this->createnewadminButton->Name = L"createnewadminButton";
    this->createnewadminButton->Size = System::Drawing::Size(398, 45);
    this->createnewadminButton->TabIndex = 10;
    this->createnewadminButton->Text = L"Create New Admin";
    this->createnewadminButton->UseVisualStyleBackColor = true;
    this->createnewadminButton->Click += gcnew System::EventHandler(this, &Main::createnewadminButton_Click);
    //
    // lastnameLabel
    //
    this->lastnameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->lastnameLabel->AutoSize = true;
    this->lastnameLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->lastnameLabel->Location = System::Drawing::Point(220, 154);
    this->lastnameLabel->Name = L"lastnameLabel";
    this->lastnameLabel->Size = System::Drawing::Size(151, 37);
    this->lastnameLabel->TabIndex = 8;
    this->lastnameLabel->Text = L"Last Name";
    //
    // firstnamerichTextBox
    //
    this->firstnamerichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->firstnamerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->firstnamerichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->firstnamerichTextBox->Location = System::Drawing::Point(634, 90);
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
    this->newWaiterPanel->Location = System::Drawing::Point(0, 0);
    this->newWaiterPanel->Name = L"newWaiterPanel";
    this->newWaiterPanel->Size = System::Drawing::Size(1300, 782);
    this->newWaiterPanel->TabIndex = 14;
    this->newWaiterPanel->Visible = false;
    //
    // waiterSalaryLabel
    //
    this->waiterSalaryLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterSalaryLabel->AutoSize = true;
    this->waiterSalaryLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->waiterSalaryLabel->Location = System::Drawing::Point(163, 510);
    this->waiterSalaryLabel->Name = L"waiterSalaryLabel";
    this->waiterSalaryLabel->Size = System::Drawing::Size(97, 37);
    this->waiterSalaryLabel->TabIndex = 22;
    this->waiterSalaryLabel->Text = L"Salary";
    //
    // WaiterEmploymentTypeComboBox
    //
    this->WaiterEmploymentTypeComboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->WaiterEmploymentTypeComboBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->WaiterEmploymentTypeComboBox->FormattingEnabled = true;
    this->WaiterEmploymentTypeComboBox->Items->AddRange(
        gcnew cli::array<System::Object ^>(3){L"Full Time", L"Part Time", L"Casual"});
    this->WaiterEmploymentTypeComboBox->Location = System::Drawing::Point(579, 456);
    this->WaiterEmploymentTypeComboBox->Name = L"WaiterEmploymentTypeComboBox";
    this->WaiterEmploymentTypeComboBox->Size = System::Drawing::Size(121, 45);
    this->WaiterEmploymentTypeComboBox->TabIndex = 21;
    //
    // waiterSalaryrichTextBox
    //
    this->waiterSalaryrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterSalaryrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->waiterSalaryrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->waiterSalaryrichTextBox->Location = System::Drawing::Point(579, 519);
    this->waiterSalaryrichTextBox->MaxLength = 10;
    this->waiterSalaryrichTextBox->Name = L"waiterSalaryrichTextBox";
    this->waiterSalaryrichTextBox->Size = System::Drawing::Size(180, 48);
    this->waiterSalaryrichTextBox->TabIndex = 20;
    this->waiterSalaryrichTextBox->Text = L"";
    //
    // waiterAddressrichTextBox
    //
    this->waiterAddressrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterAddressrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->waiterAddressrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->waiterAddressrichTextBox->Location = System::Drawing::Point(579, 390);
    this->waiterAddressrichTextBox->MaxLength = 10;
    this->waiterAddressrichTextBox->Name = L"waiterAddressrichTextBox";
    this->waiterAddressrichTextBox->Size = System::Drawing::Size(558, 48);
    this->waiterAddressrichTextBox->TabIndex = 19;
    this->waiterAddressrichTextBox->Text = L"";
    //
    // waiterAgerichTextBox
    //
    this->waiterAgerichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterAgerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->waiterAgerichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->waiterAgerichTextBox->Location = System::Drawing::Point(579, 324);
    this->waiterAgerichTextBox->MaxLength = 10;
    this->waiterAgerichTextBox->Name = L"waiterAgerichTextBox";
    this->waiterAgerichTextBox->Size = System::Drawing::Size(180, 48);
    this->waiterAgerichTextBox->TabIndex = 18;
    this->waiterAgerichTextBox->Text = L"";
    //
    // waiterGenderrichTextBox
    //
    this->waiterGenderrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterGenderrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->waiterGenderrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->waiterGenderrichTextBox->Location = System::Drawing::Point(579, 258);
    this->waiterGenderrichTextBox->MaxLength = 10;
    this->waiterGenderrichTextBox->Name = L"waiterGenderrichTextBox";
    this->waiterGenderrichTextBox->Size = System::Drawing::Size(180, 48);
    this->waiterGenderrichTextBox->TabIndex = 17;
    this->waiterGenderrichTextBox->Text = L"";
    //
    // waiterEmploymentTypeLabel
    //
    this->waiterEmploymentTypeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterEmploymentTypeLabel->AutoSize = true;
    this->waiterEmploymentTypeLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->waiterEmploymentTypeLabel->Location = System::Drawing::Point(165, 446);
    this->waiterEmploymentTypeLabel->Name = L"waiterEmploymentTypeLabel";
    this->waiterEmploymentTypeLabel->Size = System::Drawing::Size(244, 37);
    this->waiterEmploymentTypeLabel->TabIndex = 16;
    this->waiterEmploymentTypeLabel->Text = L"Employment Type";
    //
    // waiterAdressLabel
    //
    this->waiterAdressLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterAdressLabel->AutoSize = true;
    this->waiterAdressLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->waiterAdressLabel->Location = System::Drawing::Point(165, 382);
    this->waiterAdressLabel->Name = L"waiterAdressLabel";
    this->waiterAdressLabel->Size = System::Drawing::Size(123, 37);
    this->waiterAdressLabel->TabIndex = 15;
    this->waiterAdressLabel->Text = L"Address";
    //
    // waiterAgeLabel
    //
    this->waiterAgeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterAgeLabel->AutoSize = true;
    this->waiterAgeLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->waiterAgeLabel->Location = System::Drawing::Point(165, 318);
    this->waiterAgeLabel->Name = L"waiterAgeLabel";
    this->waiterAgeLabel->Size = System::Drawing::Size(67, 37);
    this->waiterAgeLabel->TabIndex = 14;
    this->waiterAgeLabel->Text = L"Age";
    //
    // waiterGenderLabel
    //
    this->waiterGenderLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterGenderLabel->AutoSize = true;
    this->waiterGenderLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->waiterGenderLabel->Location = System::Drawing::Point(165, 254);
    this->waiterGenderLabel->Name = L"waiterGenderLabel";
    this->waiterGenderLabel->Size = System::Drawing::Size(109, 37);
    this->waiterGenderLabel->TabIndex = 13;
    this->waiterGenderLabel->Text = L"Gender";
    //
    // waiterLastNamerichTextBox
    //
    this->waiterLastNamerichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterLastNamerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->waiterLastNamerichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->waiterLastNamerichTextBox->Location = System::Drawing::Point(579, 192);
    this->waiterLastNamerichTextBox->MaxLength = 10;
    this->waiterLastNamerichTextBox->Name = L"waiterLastNamerichTextBox";
    this->waiterLastNamerichTextBox->Size = System::Drawing::Size(180, 48);
    this->waiterLastNamerichTextBox->TabIndex = 12;
    this->waiterLastNamerichTextBox->Text = L"";
    //
    // waiterCreateNewButton
    //
    this->waiterCreateNewButton->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterCreateNewButton->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->waiterCreateNewButton->ForeColor = System::Drawing::Color::DodgerBlue;
    this->waiterCreateNewButton->Location = System::Drawing::Point(460, 612);
    this->waiterCreateNewButton->Name = L"waiterCreateNewButton";
    this->waiterCreateNewButton->Size = System::Drawing::Size(398, 45);
    this->waiterCreateNewButton->TabIndex = 10;
    this->waiterCreateNewButton->Text = L"Create New Waiter";
    this->waiterCreateNewButton->UseVisualStyleBackColor = true;
    this->waiterCreateNewButton->Click += gcnew System::EventHandler(this, &Main::waiterCreateNewButton_Click);
    //
    // waiterLastNameLabel
    //
    this->waiterLastNameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterLastNameLabel->AutoSize = true;
    this->waiterLastNameLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->waiterLastNameLabel->Location = System::Drawing::Point(165, 190);
    this->waiterLastNameLabel->Name = L"waiterLastNameLabel";
    this->waiterLastNameLabel->Size = System::Drawing::Size(151, 37);
    this->waiterLastNameLabel->TabIndex = 8;
    this->waiterLastNameLabel->Text = L"Last Name";
    //
    // waiterFirstNameLabel
    //
    this->waiterFirstNameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterFirstNameLabel->AutoSize = true;
    this->waiterFirstNameLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->waiterFirstNameLabel->Location = System::Drawing::Point(163, 126);
    this->waiterFirstNameLabel->Name = L"waiterFirstNameLabel";
    this->waiterFirstNameLabel->Size = System::Drawing::Size(153, 37);
    this->waiterFirstNameLabel->TabIndex = 7;
    this->waiterFirstNameLabel->Text = L"First Name";
    //
    // waiterFirstNamerichTextBox
    //
    this->waiterFirstNamerichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->waiterFirstNamerichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->waiterFirstNamerichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->waiterFirstNamerichTextBox->Location = System::Drawing::Point(579, 126);
    this->waiterFirstNamerichTextBox->MaxLength = 10;
    this->waiterFirstNamerichTextBox->Name = L"waiterFirstNamerichTextBox";
    this->waiterFirstNamerichTextBox->Size = System::Drawing::Size(180, 48);
    this->waiterFirstNamerichTextBox->TabIndex = 9;
    this->waiterFirstNamerichTextBox->Text = L"";
    //
    // CurrentTimeTimer
    //
    this->CurrentTimeTimer->Tick += gcnew System::EventHandler(this, &Main::timer1_Tick);
    //
    // tablesLayoutPanel
    //
    this->tablesLayoutPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(125)));
    this->tablesLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->tablesLayoutPanel->Location = System::Drawing::Point(396, 102);
    this->tablesLayoutPanel->Name = L"tablesLayoutPanel";
    this->tablesLayoutPanel->Size = System::Drawing::Size(904, 625);
    this->tablesLayoutPanel->TabIndex = 0;
    this->tablesLayoutPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::addTables);
    //
    // newTablesPanel
    //
    this->newTablesPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
    this->newTablesPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->newTablesPanel->Controls->Add(this->createNewTableButton);
    this->newTablesPanel->Controls->Add(this->tablesSeatsLabel);
    this->newTablesPanel->Controls->Add(this->tablesSeatsrichTextBox);
    this->newTablesPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->newTablesPanel->Location = System::Drawing::Point(396, 102);
    this->newTablesPanel->Name = L"newTablesPanel";
    this->newTablesPanel->Size = System::Drawing::Size(904, 625);
    this->newTablesPanel->TabIndex = 1;
    this->newTablesPanel->Visible = false;
    //
    // createNewTableButton
    //
    this->createNewTableButton->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->createNewTableButton->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->createNewTableButton->ForeColor = System::Drawing::Color::DodgerBlue;
    this->createNewTableButton->Location = System::Drawing::Point(250, 340);
    this->createNewTableButton->Name = L"createNewTableButton";
    this->createNewTableButton->Size = System::Drawing::Size(398, 45);
    this->createNewTableButton->TabIndex = 12;
    this->createNewTableButton->Text = L"Create New Table";
    this->createNewTableButton->UseVisualStyleBackColor = true;
    this->createNewTableButton->Click += gcnew System::EventHandler(this, &Main::createNewTableButton_Click);
    //
    // tablesSeatsLabel
    //
    this->tablesSeatsLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->tablesSeatsLabel->AutoSize = true;
    this->tablesSeatsLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->tablesSeatsLabel->Location = System::Drawing::Point(358, 236);
    this->tablesSeatsLabel->Name = L"tablesSeatsLabel";
    this->tablesSeatsLabel->Size = System::Drawing::Size(177, 37);
    this->tablesSeatsLabel->TabIndex = 10;
    this->tablesSeatsLabel->Text = L"Tables seats";
    //
    // tablesSeatsrichTextBox
    //
    this->tablesSeatsrichTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->tablesSeatsrichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->tablesSeatsrichTextBox->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold));
    this->tablesSeatsrichTextBox->Location = System::Drawing::Point(356, 278);
    this->tablesSeatsrichTextBox->MaxLength = 10;
    this->tablesSeatsrichTextBox->Name = L"tablesSeatsrichTextBox";
    this->tablesSeatsrichTextBox->Size = System::Drawing::Size(180, 48);
    this->tablesSeatsrichTextBox->TabIndex = 11;
    this->tablesSeatsrichTextBox->Text = L"";
    //
    // tableLayoutPanel1
    //
    this->tableLayoutPanel1->BackColor = System::Drawing::Color::Black;
    this->tableLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
    this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
    this->tableLayoutPanel1->ColumnCount = 8;
    this->tableLayoutPanel1->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
    this->tableLayoutPanel1->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
    this->tableLayoutPanel1->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
    this->tableLayoutPanel1->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
    this->tableLayoutPanel1->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
    this->tableLayoutPanel1->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
    this->tableLayoutPanel1->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
    this->tableLayoutPanel1->ColumnStyles->Add(
        (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
    this->tableLayoutPanel1->Controls->Add(this->footerTimeLabel, 0, 0);
    this->tableLayoutPanel1->Controls->Add(this->footerTimeValueLabel, 1, 0);
    this->tableLayoutPanel1->Controls->Add(this->footerDateValueLabel, 3, 0);
    this->tableLayoutPanel1->Controls->Add(this->footerDatelabel, 2, 0);
    this->tableLayoutPanel1->Controls->Add(this->footerVacantTablesValueLabel, 7, 0);
    this->tableLayoutPanel1->Controls->Add(this->footerVacantTableslabel, 6, 0);
    this->tableLayoutPanel1->Controls->Add(this->footerStaffValueLabel, 5, 0);
    this->tableLayoutPanel1->Controls->Add(this->footerStafflabel, 4, 0);
    this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
    this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
    this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
    this->tableLayoutPanel1->RowCount = 1;
    this->tableLayoutPanel1->RowStyles->Add(
        (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
    this->tableLayoutPanel1->Size = System::Drawing::Size(1296, 32);
    this->tableLayoutPanel1->TabIndex = 1;
    //
    // footerTimeLabel
    //
    this->footerTimeLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->footerTimeLabel->ForeColor = System::Drawing::SystemColors::Control;
    this->footerTimeLabel->Location = System::Drawing::Point(5, 2);
    this->footerTimeLabel->Name = L"footerTimeLabel";
    this->footerTimeLabel->Size = System::Drawing::Size(153, 28);
    this->footerTimeLabel->TabIndex = 16;
    this->footerTimeLabel->Text = L"Time";
    //
    // footerTimeValueLabel
    //
    this->footerTimeValueLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->footerTimeValueLabel->ForeColor = System::Drawing::Color::LimeGreen;
    this->footerTimeValueLabel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
    this->footerTimeValueLabel->Location = System::Drawing::Point(166, 2);
    this->footerTimeValueLabel->Name = L"footerTimeValueLabel";
    this->footerTimeValueLabel->Size = System::Drawing::Size(153, 28);
    this->footerTimeValueLabel->TabIndex = 20;
    this->footerTimeValueLabel->Text = L"NULL";
    this->footerTimeValueLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
    //
    // footerDateValueLabel
    //
    this->footerDateValueLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->footerDateValueLabel->ForeColor = System::Drawing::Color::LimeGreen;
    this->footerDateValueLabel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
    this->footerDateValueLabel->Location = System::Drawing::Point(488, 2);
    this->footerDateValueLabel->Name = L"footerDateValueLabel";
    this->footerDateValueLabel->Size = System::Drawing::Size(153, 28);
    this->footerDateValueLabel->TabIndex = 21;
    this->footerDateValueLabel->Text = L"NULL";
    this->footerDateValueLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
    //
    // footerDatelabel
    //
    this->footerDatelabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->footerDatelabel->ForeColor = System::Drawing::SystemColors::Control;
    this->footerDatelabel->Location = System::Drawing::Point(327, 2);
    this->footerDatelabel->Name = L"footerDatelabel";
    this->footerDatelabel->Size = System::Drawing::Size(153, 28);
    this->footerDatelabel->TabIndex = 17;
    this->footerDatelabel->Text = L"Date";
    //
    // footerVacantTablesValueLabel
    //
    this->footerVacantTablesValueLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->footerVacantTablesValueLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->footerVacantTablesValueLabel->ForeColor = System::Drawing::Color::LimeGreen;
    this->footerVacantTablesValueLabel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
    this->footerVacantTablesValueLabel->Location = System::Drawing::Point(1133, 2);
    this->footerVacantTablesValueLabel->Name = L"footerVacantTablesValueLabel";
    this->footerVacantTablesValueLabel->Size = System::Drawing::Size(156, 28);
    this->footerVacantTablesValueLabel->TabIndex = 23;
    this->footerVacantTablesValueLabel->Text = L"NULL";
    this->footerVacantTablesValueLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
    //
    // footerVacantTableslabel
    //
    this->footerVacantTableslabel->Anchor = System::Windows::Forms::AnchorStyles::None;
    this->footerVacantTableslabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->footerVacantTableslabel->ForeColor = System::Drawing::SystemColors::Control;
    this->footerVacantTableslabel->Location = System::Drawing::Point(971, 2);
    this->footerVacantTableslabel->Name = L"footerVacantTableslabel";
    this->footerVacantTableslabel->Size = System::Drawing::Size(153, 28);
    this->footerVacantTableslabel->TabIndex = 19;
    this->footerVacantTableslabel->Text = L"Vacant Tables";
    //
    // footerStaffValueLabel
    //
    this->footerStaffValueLabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->footerStaffValueLabel->ForeColor = System::Drawing::Color::LimeGreen;
    this->footerStaffValueLabel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
    this->footerStaffValueLabel->Location = System::Drawing::Point(810, 2);
    this->footerStaffValueLabel->Name = L"footerStaffValueLabel";
    this->footerStaffValueLabel->Size = System::Drawing::Size(153, 28);
    this->footerStaffValueLabel->TabIndex = 22;
    this->footerStaffValueLabel->Text = L"NULL";
    this->footerStaffValueLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
    //
    // footerStafflabel
    //
    this->footerStafflabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
        (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
          System::Windows::Forms::AnchorStyles::Left) |
         System::Windows::Forms::AnchorStyles::Right));
    this->footerStafflabel->Font =
        (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->footerStafflabel->ForeColor = System::Drawing::SystemColors::Control;
    this->footerStafflabel->Location = System::Drawing::Point(649, 2);
    this->footerStafflabel->Name = L"footerStafflabel";
    this->footerStafflabel->Size = System::Drawing::Size(153, 28);
    this->footerStafflabel->TabIndex = 18;
    this->footerStafflabel->Text = L"Staff";
    //
    // statusPanel
    //
    this->statusPanel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
    this->statusPanel->Controls->Add(this->statusLabel);
    this->statusPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
    this->statusPanel->Location = System::Drawing::Point(0, 32);
    this->statusPanel->Name = L"statusPanel";
    this->statusPanel->Size = System::Drawing::Size(1296, 19);
    this->statusPanel->TabIndex = 0;
    //
    // statusLabel
    //
    this->statusLabel->AutoSize = true;
    this->statusLabel->Font =
        (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
                                     System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->statusLabel->ForeColor = System::Drawing::Color::Lime;
    this->statusLabel->Location = System::Drawing::Point(2, 3);
    this->statusLabel->Name = L"statusLabel";
    this->statusLabel->Size = System::Drawing::Size(43, 13);
    this->statusLabel->TabIndex = 0;
    this->statusLabel->Text = L"Ready";
    //
    // footerPanel
    //
    this->footerPanel->BackColor =
        System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(92)),
                                         static_cast<System::Int32>(static_cast<System::Byte>(115)));
    this->footerPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
    this->footerPanel->Controls->Add(this->tableLayoutPanel1);
    this->footerPanel->Controls->Add(this->statusPanel);
    this->footerPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
    this->footerPanel->Location = System::Drawing::Point(0, 727);
    this->footerPanel->Name = L"footerPanel";
    this->footerPanel->Size = System::Drawing::Size(1300, 55);
    this->footerPanel->TabIndex = 0;
    //
    // Main
    //
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(1300, 782);
    this->Controls->Add(this->adminPanel);
    this->Controls->Add(this->tablesLayoutPanel);
    this->Controls->Add(this->clockinPanel);
    this->Controls->Add(this->entreeMenuPanel);
    this->Controls->Add(this->dessertMenuPanel);
    this->Controls->Add(this->drinksMenuPanel);
    this->Controls->Add(this->mainMenuPanel);
    this->Controls->Add(this->newTablesPanel);
    this->Controls->Add(this->sidePanel);
    this->Controls->Add(this->adminLoginPanel);
    this->Controls->Add(this->newAdminPanel);
    this->Controls->Add(this->headerPanel);
    this->Controls->Add(this->footerPanel);
    this->Controls->Add(this->newWaiterPanel);
    this->Controls->Add(this->addItemPanel);
    this->Name = L"Main";
    this->Text = L"RMSPOS - Restaurant Management System and Point of Sale";
    this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
    this->sidePanel->ResumeLayout(false);
    this->viewOrderPanel->ResumeLayout(false);
    this->tableLayoutPanel2->ResumeLayout(false);
    this->tableLayoutPanel2->PerformLayout();
    this->tableLayoutPanel3->ResumeLayout(false);
    this->tableLayoutPanel3->PerformLayout();
    this->orderPanel->ResumeLayout(false);
    this->orderPanelFooterTotalString->ResumeLayout(false);
    this->orderPanelFooterTotalString->PerformLayout();
    this->orderPanelFooter->ResumeLayout(false);
    this->orderPanelFooter->PerformLayout();
    this->navigationPanel->ResumeLayout(false);
    this->sidePanelHeaderPanel->ResumeLayout(false);
    this->adminPanel->ResumeLayout(false);
    this->removePanel->ResumeLayout(false);
    this->removePanel->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Remove))->EndInit();
    this->contactPanel->ResumeLayout(false);
    this->contactPanel->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Contact))->EndInit();
    this->addPanel->ResumeLayout(false);
    this->addPanel->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->Add))->EndInit();
    this->headerPanel->ResumeLayout(false);
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
    this->tableLayoutPanel1->ResumeLayout(false);
    this->statusPanel->ResumeLayout(false);
    this->statusPanel->PerformLayout();
    this->footerPanel->ResumeLayout(false);
    this->ResumeLayout(false);
    this->PerformLayout();
}

System::Void RMSPOS::Main::clockButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    hideAll();
    clockinPanel->Show();
    headerNavigationLabel->Text = "Staff Clock In";
}

System::Void RMSPOS::Main::adminButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{

    if (Admin::adminsVector.size() == 0)
    {
        if (MessageBox::Show("It appears there are no appointed admins yet. "
                             "Would you like to create admin account?",
                             "Confirm", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
        {
            hideAll();
            adminPanel->Show();
            headerNavigationLabel->Text = "Create new Admin";
        }
    }
    else
    {
        hideAll();
        adminLoginPanel->Show();
        headerNavigationLabel->Text = "Admin Log in";
    }
}

System::Void RMSPOS::Main::LoginButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    std::vector<Admin>::iterator iter1, iter2, end1, end2;
    for (iter1 = Admin::adminsVector.begin(), end1 = Admin::adminsVector.end(); iter1 != end1; ++iter1)
    {
        string inputUsername = (iter1)->getUsername();
        string inputPassword = (iter1)->getPassword();
        if ((iter1)->getUsername() == toUnmannged(adminNumberrichTextBox->Text) &&
            (iter1)->getPassword() == toUnmannged(adminPasswordrichTextBox->Text))
        {
            hideAll();
            adminPanel->Show();
            headerNavigationLabel->Text = "Admin Dashboard";
            loginFailedLabel->Hide();
            break;
        }
        else
        {
            loginFailedLabel->Show();
        }
    }
}

System::Void RMSPOS::Main::drinkButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    hideAll();
    drinksMenuPanel->Show();
    headerNavigationLabel->Text = "Drinks Menu";
}

System::Void RMSPOS::Main::addMenuItemButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    hideAll();
    addItemPanel->Show();
    headerNavigationLabel->Text = "Add New Item";
}

System::Void RMSPOS::Main::addDrinkButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{

    std::string std_itemNamerichTextBox = toUnmannged(itemNamerichTextBox->Text);
    int itemPrice = Convert::ToInt32(itemPricerichTextBox->Text);
    std::string std_itemCategory = toUnmannged(itemCategory->Text);
    if (std_itemCategory == "Drink")
    {
        Drink newDrink(std_itemNamerichTextBox, itemPrice, true);
        System::Windows::Forms::Button ^ button;
        button = (gcnew System::Windows::Forms::Button());
        this->drinksMenuPanel->Controls->Add(button, 0, 0);
        button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        button->Location = System::Drawing::Point(3, 3);
        button->Text = itemNamerichTextBox->Text;
        button->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10, System::Drawing::FontStyle::Bold));
        button->Size = System::Drawing::Size(71, 75);
        button->TabIndex = 0;
        button->UseVisualStyleBackColor = true;
        button->Visible = true;
        button->Click += gcnew System::EventHandler(this, &Main::menuItem_Clicked);
        hideAll();
        drinksMenuPanel->Show();
        headerNavigationLabel->Text = "Drinks Menu";
        Drink::menuVector.push_back(make_pair(std_itemNamerichTextBox, itemPrice));
    }
    else if (std_itemCategory == "Entree")
    {
        Entree newEntree(std_itemNamerichTextBox, itemPrice, true);
        System::Windows::Forms::Button ^ button;
        button = (gcnew System::Windows::Forms::Button());
        this->entreeMenuPanel->Controls->Add(button, 0, 0);
        button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        button->Location = System::Drawing::Point(3, 3);
        button->Text = itemNamerichTextBox->Text;
        button->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10, System::Drawing::FontStyle::Bold));
        button->Size = System::Drawing::Size(71, 75);
        button->TabIndex = 100;
        button->UseVisualStyleBackColor = true;
        button->Visible = newEntree.getvisible();

        hideAll();
        entreeMenuPanel->Show();
        headerNavigationLabel->Text = "Entrees Menu";
        Entree::menuVector.push_back(make_pair(std_itemNamerichTextBox, itemPrice));
        button->Click += gcnew System::EventHandler(this, &Main::menuItem_Clicked);
    }
    else if (std_itemCategory == "Main")
    {
        Mains newMain(std_itemNamerichTextBox, itemPrice, true);
        System::Windows::Forms::Button ^ button;
        button = (gcnew System::Windows::Forms::Button());
        this->mainMenuPanel->Controls->Add(button, 0, 0);
        button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        button->Location = System::Drawing::Point(3, 3);
        button->Text = itemNamerichTextBox->Text;
        button->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10, System::Drawing::FontStyle::Bold));
        button->Size = System::Drawing::Size(71, 75);
        button->TabIndex = 1;
        button->UseVisualStyleBackColor = true;
        button->Visible = newMain.getvisible();

        hideAll();
        mainMenuPanel->Show();
        headerNavigationLabel->Text = "Mains Menu";
        Mains::menuVector.push_back(make_pair(std_itemNamerichTextBox, itemPrice));
        button->Click += gcnew System::EventHandler(this, &Main::menuItem_Clicked);
    }
    else if (std_itemCategory == "Dessert")
    {
        Dessert newDessert(std_itemNamerichTextBox, itemPrice, true);
        System::Windows::Forms::Button ^ button;
        button = (gcnew System::Windows::Forms::Button());
        this->dessertMenuPanel->Controls->Add(button, 0, 0);
        button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        button->Location = System::Drawing::Point(3, 3);
        button->Text = itemNamerichTextBox->Text;
        button->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10, System::Drawing::FontStyle::Bold));
        button->Size = System::Drawing::Size(71, 75);
        button->TabIndex = 1;
        button->UseVisualStyleBackColor = true;
        button->Visible = newDessert.getvisible();
        hideAll();
        dessertMenuPanel->Show();
        headerNavigationLabel->Text = "Desserts Menu";
        Dessert::menuVector.push_back(make_pair(std_itemNamerichTextBox, itemPrice));
        button->Click += gcnew System::EventHandler(this, &Main::menuItem_Clicked);
    }
    else
    {
        errorLabel->Visible = true;
    }
}

System::Void RMSPOS::Main::entreeButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{

    hideAll();
    entreeMenuPanel->Show();
    headerNavigationLabel->Text = "Entrees Menu";
}

System::Void RMSPOS::Main::mainButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{

    hideAll();
    headerNavigationLabel->Text = "Mains Menu";
    mainMenuPanel->Show();
}

System::Void RMSPOS::Main::dessertButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    hideAll();
    dessertMenuPanel->Show();
    headerNavigationLabel->Text = "Desserts Menu";
}

System::Void RMSPOS::Main::addManagerButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    hideAll();
    headerNavigationLabel->Text = "Create New Admin";
    newAdminPanel->Show();
}

System::Void RMSPOS::Main::createnewadminButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    try
    {
        std::string std_firstnameAdmin = toUnmannged(firstnamerichTextBox->Text);
        std::string std_lastnameAdmin = toUnmannged(lastnamerichTextBox->Text);
        int std_salaryAdmin = Convert::ToInt32(salaryrichTextBox->Text);
        int std_ageAdmin = Convert::ToInt32(agerichTextBox->Text);
        std::string std_genderAdmin = toUnmannged(genderrichTextBox->Text);
        std::string std_addressAdmin = toUnmannged(addressrichTextBox->Text);
        std::string std_employmenttypeAdmin = toUnmannged(employmentTypeComboBox->Text);
        Admin newAdmin(std_firstnameAdmin, std_lastnameAdmin, std_salaryAdmin, std_ageAdmin, std_genderAdmin,
                       std_addressAdmin, std_employmenttypeAdmin);
        String ^ newAdminUsername = toManaged(newAdmin.getUsername());
        String ^ newAdminPassword = toManaged(newAdmin.getPassword());
        String ^ msg = "Admin has been created successfully!\n\nThe following "
                       "credentials have been created for them automatically. "
                       "Next time they log in, they will be asked to change "
                       "their credentials to a more secured ones.\n\nUsername: " +
                       newAdminUsername + "\nPassword: " + newAdminPassword;
        MessageBox::Show(msg);
        Admin::adminsVector.push_back(newAdmin);
        hideAll();
        adminPanel->Show();
        headerNavigationLabel->Text = "Admin Dashboard";
        statusLabel->Text = "Ready";
    }

    catch (...)

    {
        statusLabel->Text = "Admin has not been created successfully! Please check "
                            "your details are correct.";
    }
}

System::Void RMSPOS::Main::addWaiterButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    hideAll();
    newWaiterPanel->Show();
    headerNavigationLabel->Text = "Create New Staff";
}

System::Void RMSPOS::Main::waiterCreateNewButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{

    try
    {
        std::string std_firstnameWaiter = toUnmannged(waiterFirstNamerichTextBox->Text);
        std::string std_lastnameWaiter = toUnmannged(waiterLastNamerichTextBox->Text);
        int std_salaryWaiter = Convert::ToInt32(waiterSalaryrichTextBox->Text);
        int std_ageWaiter = Convert::ToInt32(waiterAgerichTextBox->Text);
        std::string std_genderWaiter = toUnmannged(waiterGenderrichTextBox->Text);
        std::string std_addressWaiter = toUnmannged(waiterAddressrichTextBox->Text);
        std::string std_employmenttypeWaiter = toUnmannged(WaiterEmploymentTypeComboBox->Text);
        Waiter newWaiter(std_firstnameWaiter, std_lastnameWaiter, std_salaryWaiter, std_ageWaiter, std_genderWaiter,
                         std_addressWaiter, std_employmenttypeWaiter);
        newWaiter.changeCredentials(newWaiter.getInitials(), newWaiter.generateID());
        String ^ newWaiternUsername = toManaged(newWaiter.getInitials());
        String ^ newWaiterPassword = toManaged(newWaiter.getPassword());
        String ^ msg = "Waiter has been created successfully!\n\nThey will need "
                       "these details to clock in and clock out.\n\nInitials: " +
                       newWaiternUsername + "\nPassword: " + newWaiterPassword;
        MessageBox::Show(msg);
        Waiter::waitersVector.push_back(newWaiter);
        hideAll();
        adminPanel->Show();
        headerNavigationLabel->Text = "Admin Dashboard";
    }

    catch (...)

    {
        statusLabel->Text = "Waiter has not been created successfully! Please check "
                            "your details are correct.";
    }
}

System::Void RMSPOS::Main::clockinButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    vector<Waiter>::iterator iter1, end1;
    bool loginSuccessful = false;
    for (iter1 = Waiter::waitersVector.begin(), end1 = Waiter::waitersVector.end(); iter1 != end1; ++iter1)
    {
        if (iter1->getUsername() == toUnmannged(staffnumberrichTextBox->Text) &&
            toUnmannged(staffpasswordrichTextBox->Text) == iter1->getPassword())
        {
            String ^ firstName = toManaged((iter1)->getFirstName());
            loginSuccessful = true;
            Waiter::clockedinWaiters.push_back(*iter1);
            String ^ timeNow = getTime();
            String ^ msg = "Hello " + firstName + "!\n\nYou successfully clocked in at " + timeNow;
            MessageBox::Show(msg);
            clockinFailedLabel->Hide();
            break;
        }
    }

    if (!loginSuccessful)
    {
        statusLabel->Text = "Failed to clock in. Please check your details are correct.";
    }
}

System::Void RMSPOS::Main::timer1_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
    DateTime datetime = DateTime::Now;
    footerTimeValueLabel->Text = datetime.ToLongTimeString();
    footerDateValueLabel->Text = datetime.ToString("dd/MM/yyyy");
    footerStaffValueLabel->Text = Convert::ToString(Waiter::clockedinWaiters.size());
}

System::Void RMSPOS::Main::addNewTableButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    hideAll();
    newTablesPanel->Show();
    headerNavigationLabel->Text = "Create New Table";
}

System::Void RMSPOS::Main::createNewTableButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    createNewTableButton->Tag = "Activate";
    String ^ msg = "Please use the mouse left button to indicate where you want "
                   "the new table to be positioned.";
    MessageBox::Show(msg);
    hideAll();
    tablesLayoutPanel->Show();
    headerNavigationLabel->Text = "Tables";
}

System::Void RMSPOS::Main::tablesButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    hideAll();
    tablesLayoutPanel->Show();
    headerNavigationLabel->Text = "Tables";
}

System::Void RMSPOS::Main::addTables(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
    if (createNewTableButton->Tag == "Activate")
    {

        try
        {
            int tableNumber = static_cast<int>(Table::tablesVector.size());
            string newTableName = "Table " + to_string(tableNumber);
            Table newTable(newTableName);
            Table::tablesVector.push_back(newTable);
            Button ^ newButton = gcnew Button();
            newButton->Name = toManaged("Table " + to_string(tableNumber));
            newButton->Font =
                (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            newButton->Text = Convert::ToString("Table " + tableNumber);
            newButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom));
            newButton->BackColor = System::Drawing::SystemColors::ControlLight;
            newButton->Location = System::Drawing::Point(e->Location.X - Convert::ToInt32(newButton->Size.Width),
                                                         e->Location.Y - Convert::ToInt32(newButton->Size.Height));
            newButton->Size = System::Drawing::Size(100, 100);
            newButton->TabIndex = 0;
            newButton->UseVisualStyleBackColor = false;
            newButton->Click += gcnew System::EventHandler(this, &Main::table_Click);
            this->tablesLayoutPanel->Controls->Add(newButton);
            hideAll();
            tablesLayoutPanel->Show();
            createNewTableButton->Tag = "Deactivate";
            String ^ msg = "Table has been created successfully!";
            MessageBox::Show(msg);
        }

        catch (...)
        {
            statusLabel->Text = "Table has not been created successfully! Please try again.";
            hideAll();
            newTablesPanel->Show();
            headerNavigationLabel->Text = "Create New Table";
        }
    }
}

System::Void RMSPOS::Main::menuItem_Clicked(System::Object ^ sender, System::EventArgs ^ e)
{
    int orderSum = 0;
    orderPanel->Visible = true;
    viewOrderPanel->Visible = false;
    Button ^ button = (Button ^) sender;
    vector<pair<string, int>>::iterator iter, end;
    for (iter = Drink::menuVector.begin(), end = Drink::menuVector.end(); iter != end; ++iter)
    {
        std::string std_firstnameAdmin = toUnmannged(button->Text);
        if ((iter->first) == std_firstnameAdmin)
        {
            Label ^ nameLabel = gcnew Label();
            nameLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            nameLabel->Font =
                (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            nameLabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
            nameLabel->Size = System::Drawing::Size(140, 70);
            nameLabel->TabIndex = 0;
            String ^ itemName = toManaged(iter->first);
            nameLabel->Text = itemName;
            nameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

            Label ^ priceLabel = gcnew Label();
            priceLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            priceLabel->Font =
                (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            priceLabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
            priceLabel->Size = System::Drawing::Size(140, 70);
            priceLabel->TabIndex = 0;
            priceLabel->Text = Convert::ToString(iter->second);
            priceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            orderLayoutPanel->Controls->Add(nameLabel, 0, orderLayoutPanel->RowCount);
            orderLayoutPanel->Controls->Add(priceLabel, 1, orderLayoutPanel->RowCount);
            orderLayoutPanel->RowCount++;
            Table::tempTableOrder.push_back(make_pair(iter->first, iter->second));
            vector<pair<string, int>>::iterator iterTempTableOrder, endTempTableOrder;
            for (iterTempTableOrder = Table::tempTableOrder.begin(), endTempTableOrder = Table::tempTableOrder.end();
                 iterTempTableOrder != endTempTableOrder; ++iterTempTableOrder)
            {
                orderSum += iterTempTableOrder->second;
            }
            orderPanelFooterTotalInt->Text = Convert::ToString(orderSum);
        }
    }
}

System::Void RMSPOS::Main::confirmOrderLayoutPanelTableLabel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    confirmOrderLayoutPanelTableLabel->Visible = false;
    clearOrderLayoutPanelTableLabel->Visible = false;
    eatinOrderLayoutPanelTableLabel->Visible = true;
    eatoutOrderLayoutPanelTableLabel->Visible = true;
}

System::Void RMSPOS::Main::eatinOrderLayoutPanelTableLabel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    tablesLayoutPanel->Visible = true;
}

System::Void RMSPOS::Main::table_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    Button ^ button = (Button ^) sender;
    Table::activeTable = toUnmannged(button->Text);
    orderPanel->Visible = false;
    viewOrderPanel->Visible = true;
    vector<Table>::iterator iter1, end1;
    vector<pair<string, int>>::iterator iter2, end2, iter3, end3;
    tableOrderLayoutPanel->Controls->Clear();
    int counter = 0;
    for (iter1 = Table::tablesVector.begin(), end1 = Table::tablesVector.end(); iter1 != end1; ++iter1)
    {
        String ^ tableName = toManaged(iter1->getTableName());
        std::string tableNameString = toUnmannged(button->Text);
        if (button->Text == tableName && Table::tempTableOrder.size() > 0)
        {
            for (iter2 = Table::tempTableOrder.begin(), end2 = Table::tempTableOrder.end(); iter2 != end2; ++iter2)
            {
                iter1->addOrder(iter2->first, iter2->second);
            }
            button->BackColor = System::Drawing::Color::Red;
            Table::tempTableOrder.clear();
            orderLayoutPanel->Controls->Clear();
        }
        else if (button->Text == tableName && Table::tempTableOrder.size() == 0)
        {
            vector<pair<string, int>> tableOrder = iter1->getOrder();
            vector<std::reference_wrapper<Label ^>> nameLabelVector;
            vector<std::reference_wrapper<Label ^>> priceLabelVector;

            for (iter3 = tableOrder.begin(), end3 = tableOrder.end(); iter3 != end3; ++iter3)
            {
                Label ^ nameLabel = gcnew Label();
                Label ^ priceLabel = gcnew Label();
                nameLabelVector.push_back(nameLabel);
                priceLabelVector.push_back(priceLabel);
                String ^ itemName = toManaged(iter3->first);
                nameLabelVector[counter].get()->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                    (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                      System::Windows::Forms::AnchorStyles::Left) |
                     System::Windows::Forms::AnchorStyles::Right));
                nameLabelVector[counter].get()->Font =
                    (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold,
                                                 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
                nameLabelVector[counter].get()->ForeColor = System::Drawing::SystemColors::ButtonFace;
                nameLabelVector[counter].get()->Size = System::Drawing::Size(140, 70);
                nameLabelVector[counter].get()->TabIndex = 0;
                nameLabelVector[counter].get()->Text = itemName;
                nameLabelVector[counter].get()->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

                priceLabelVector[counter].get()->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                    (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                      System::Windows::Forms::AnchorStyles::Left) |
                     System::Windows::Forms::AnchorStyles::Right));
                priceLabelVector[counter].get()->Font =
                    (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold,
                                                 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
                priceLabelVector[counter].get()->ForeColor = System::Drawing::SystemColors::ButtonFace;
                priceLabelVector[counter].get()->Size = System::Drawing::Size(140, 70);
                priceLabelVector[counter].get()->TabIndex = 0;
                priceLabelVector[counter].get()->Text = Convert::ToString(iter3->second);
                priceLabelVector[counter].get()->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
                tableOrderLayoutPanel->Controls->Add(nameLabelVector[counter].get(), 0, counter);
                tableOrderLayoutPanel->Controls->Add(priceLabelVector[counter].get(), 1, counter);
                tableOrderTotalPrice->Text = Convert::ToString(iter1->getOrderSum());
                counter++;
            }
        }
    }
}

System::Void RMSPOS::Main::clockOutbutton_Click(System::Object ^ sender, System::EventArgs ^ e)

{
    if (Waiter::clockedinWaiters.size() > 0)
    {
        int counter = 0;
        vector<Waiter>::iterator iter1, end1;
        bool loginSuccessful = false;
        for (iter1 = Waiter::clockedinWaiters.begin(), end1 = Waiter::clockedinWaiters.end(); iter1 != end1; ++iter1)
        {
            counter++;
            int index = std::distance(Waiter::clockedinWaiters.begin(), iter1);
            if (iter1->getUsername() == toUnmannged(staffnumberrichTextBox->Text) &&
                toUnmannged(staffpasswordrichTextBox->Text) == iter1->getPassword())
            {
                String ^ firstName = toManaged((iter1)->getFirstName());
                loginSuccessful = true;

                Waiter::clockedinWaiters.erase(Waiter::clockedinWaiters.begin() + counter - 1);

                String ^ timeNow = getTime();
                String ^ msg = "Hello " + firstName + "!\n\nYou successfully clocked out at " + timeNow;
                MessageBox::Show(msg);
                clockinFailedLabel->Hide();
                break;
            }
        }

        if (!loginSuccessful)
        {
            statusLabel->Text = "Failed to clock out. Please check your details are correct.";
        }
    }
}

System::Void RMSPOS::Main::tableOrderPayButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
}
