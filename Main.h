#pragma once
#include "Admin.h"
#include "Dessert.h"
#include "Drink.h"
#include "Entree.h"
#include "Mains.h"
#include "Table.h"
#include "Waiter.h"
#include "pch.h"

namespace RMSPOS
{

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace msclr::interop;
class Menu;
ref class Main : public System::Windows::Forms::Form
{
  public:
    Main(void);

    void hideAll();
    String ^ getDate();
    String ^ getTime();

  private:
    System::Windows::Forms::Panel ^ sidePanel;

    System::Windows::Forms::Panel ^ headerPanel;

    System::Windows::Forms::Panel ^ clockinPanel;

    System::Windows::Forms::RichTextBox ^ staffnumberrichTextBox;

    System::Windows::Forms::Label ^ staffpasswordLabel;

    System::Windows::Forms::Label ^ staffnumberLabel;

    System::Windows::Forms::Button ^ clockOutbutton;

    System::Windows::Forms::Button ^ clockinButton;

    System::Windows::Forms::RichTextBox ^ staffpasswordrichTextBox;

    System::Windows::Forms::Panel ^ adminLoginPanel;

    System::Windows::Forms::RichTextBox ^ adminPasswordrichTextBox;

    System::Windows::Forms::Button ^ LoginButton;

    System::Windows::Forms::Label ^ adminPasswordLabel;

    System::Windows::Forms::Label ^ adminNumberLabel;

    System::Windows::Forms::RichTextBox ^ adminNumberrichTextBox;

    System::Windows::Forms::Panel ^ adminPanel;

    System::Windows::Forms::Button ^ orderSuppliesButton;

    System::Windows::Forms::TableLayoutPanel ^ drinksMenuPanel;

    System::Windows::Forms::Panel ^ contactPanel;

    System::Windows::Forms::PictureBox ^ Contact;

    System::Windows::Forms::Panel ^ removePanel;

    System::Windows::Forms::PictureBox ^ Remove;

    System::Windows::Forms::Panel ^ addPanel;

    System::Windows::Forms::Button ^ addMenuItemButton;

    System::Windows::Forms::PictureBox ^ Add;

    System::Windows::Forms::Panel ^ addItemPanel;

    System::Windows::Forms::Button ^ addDrinkButton;

    System::Windows::Forms::RichTextBox ^ itemPricerichTextBox;

    System::Windows::Forms::Label ^ itemPriceLabel;

    System::Windows::Forms::Label ^ itemNameLabel;

    System::Windows::Forms::RichTextBox ^ itemNamerichTextBox;

    System::Windows::Forms::ComboBox ^ itemCategory;

    System::Windows::Forms::Button ^ addWaiterButton;

    System::Windows::Forms::Button ^ removeWaiterButton;

    System::Windows::Forms::Button ^ removeMenuItemButton;

    System::Windows::Forms::TableLayoutPanel ^ entreeMenuPanel;

    System::Windows::Forms::TableLayoutPanel ^ mainMenuPanel;

    System::Windows::Forms::TableLayoutPanel ^ dessertMenuPanel;

    System::Windows::Forms::Label ^ errorLabel;

    System::Windows::Forms::Button ^ removeManagerButton;

    System::Windows::Forms::Button ^ addManagerButton;

    System::Windows::Forms::Panel ^ newAdminPanel;

    System::Windows::Forms::Label ^ salaryLabel;

    System::Windows::Forms::ComboBox ^ employmentTypeComboBox;

    System::Windows::Forms::RichTextBox ^ salaryrichTextBox;

    System::Windows::Forms::RichTextBox ^ addressrichTextBox;

    System::Windows::Forms::RichTextBox ^ agerichTextBox;

    System::Windows::Forms::RichTextBox ^ genderrichTextBox;

    System::Windows::Forms::Label ^ employmenttypeLabel;

    System::Windows::Forms::Label ^ addressLabel;

    System::Windows::Forms::Label ^ ageLabel;

    System::Windows::Forms::Label ^ genderLabel;

    System::Windows::Forms::RichTextBox ^ lastnamerichTextBox;

    System::Windows::Forms::Button ^ createnewadminButton;

    System::Windows::Forms::Label ^ lastnameLabel;

    System::Windows::Forms::Label ^ firstnameLabel;

    System::Windows::Forms::RichTextBox ^ firstnamerichTextBox;

    System::Windows::Forms::Label ^ loginFailedLabel;
    System::Windows::Forms::Button ^ button2;

  private:
    System::Windows::Forms::Button ^ addNewTableButton;

    System::Windows::Forms::Panel ^ newWaiterPanel;
    System::Windows::Forms::Label ^ waiterSalaryLabel;
    System::Windows::Forms::ComboBox ^ WaiterEmploymentTypeComboBox;
    System::Windows::Forms::RichTextBox ^ waiterSalaryrichTextBox;
    System::Windows::Forms::RichTextBox ^ waiterAddressrichTextBox;
    System::Windows::Forms::RichTextBox ^ waiterAgerichTextBox;
    System::Windows::Forms::RichTextBox ^ waiterGenderrichTextBox;
    System::Windows::Forms::Label ^ waiterEmploymentTypeLabel;
    System::Windows::Forms::Label ^ waiterAdressLabel;
    System::Windows::Forms::Label ^ waiterAgeLabel;
    System::Windows::Forms::Label ^ waiterGenderLabel;
    System::Windows::Forms::RichTextBox ^ waiterLastNamerichTextBox;
    System::Windows::Forms::Button ^ waiterCreateNewButton;
    System::Windows::Forms::Label ^ waiterLastNameLabel;
    System::Windows::Forms::Label ^ waiterFirstNameLabel;
    System::Windows::Forms::RichTextBox ^ waiterFirstNamerichTextBox;
    System::Windows::Forms::Label ^ clockinFailedLabel;

  private:
  private:
  private:
  private:
  private:
  private:
    System::Windows::Forms::Timer ^ CurrentTimeTimer;

  private:
  private:
  private:
  private:
  private:
  private:
    System::Windows::Forms::Panel ^ tablesLayoutPanel;

  private:
    System::Windows::Forms::Panel ^ newTablesPanel;

  private:
    System::Windows::Forms::Button ^ createNewTableButton;

  private:
    System::Windows::Forms::Label ^ tablesSeatsLabel;

  private:
    System::Windows::Forms::RichTextBox ^ tablesSeatsrichTextBox;

  private:
    System::Windows::Forms::Label ^ headerNavigationLabel;

  private:
    System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel1;

  private:
    System::Windows::Forms::Label ^ footerTimeLabel;

  private:
    System::Windows::Forms::Label ^ footerTimeValueLabel;

  private:
    System::Windows::Forms::Label ^ footerDateValueLabel;

  private:
    System::Windows::Forms::Label ^ footerDatelabel;

  private:
    System::Windows::Forms::Label ^ footerVacantTablesValueLabel;

  private:
    System::Windows::Forms::Label ^ footerVacantTableslabel;

  private:
    System::Windows::Forms::Label ^ footerStaffValueLabel;

  private:
    System::Windows::Forms::Label ^ footerStafflabel;

  private:
    System::Windows::Forms::Panel ^ statusPanel;

  private:
    System::Windows::Forms::Label ^ statusLabel;

  private:
    System::Windows::Forms::Panel ^ footerPanel;

  private:
    System::Windows::Forms::Panel ^ sidePanelHeaderPanel;

  private:
    System::Windows::Forms::Label ^ headerSoftwareNameLabel;

  private:
    System::Windows::Forms::Panel ^ orderPanel;

  private:
    System::Windows::Forms::TableLayoutPanel ^ orderLayoutPanel;

  private:
    System::Windows::Forms::Button ^ confirmOrderLayoutPanelTableLabel;

  private:
    System::Windows::Forms::Panel ^ navigationPanel;

  private:
    System::Windows::Forms::Button ^ tablesButton;

  private:
    System::Windows::Forms::Button ^ adminButton;

  private:
    System::Windows::Forms::Button ^ clockButton;

  private:
    System::Windows::Forms::Button ^ dessertButton;

  private:
    System::Windows::Forms::Button ^ mainButton;

  private:
    System::Windows::Forms::Button ^ entreeButton;

  private:
    System::Windows::Forms::Button ^ drinkButton;

  private:
    System::Windows::Forms::TableLayoutPanel ^ orderPanelFooter;

  private:
    System::Windows::Forms::Label ^ orderPanelFooterTotalInt;

  private:
    System::Windows::Forms::Label ^ orderPanelFooterT;

  private:
    System::Windows::Forms::Button ^ clearOrderLayoutPanelTableLabel;

  private:
    System::Windows::Forms::TableLayoutPanel ^ orderPanelFooterTotalString;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Button ^ eatinOrderLayoutPanelTableLabel;

  private:
    System::Windows::Forms::Button ^ eatoutOrderLayoutPanelTableLabel;

  private:
    System::Windows::Forms::Panel ^ viewOrderPanel;

  private:
    System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel2;

  private:
    System::Windows::Forms::Label ^ tableOrderItemPrice;

  private:
    System::Windows::Forms::Label ^ tableOrderItemName;

  private:
    System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel3;

  private:
    System::Windows::Forms::Label ^ tableOrderTotalPrice;

  private:
    System::Windows::Forms::Label ^ tableOrderTotalName;

  private:
    System::Windows::Forms::TableLayoutPanel ^ tableOrderLayoutPanel;

  private:
    System::Windows::Forms::Button ^ tableOrderPayButton;

  private:
    System::ComponentModel::IContainer ^ components;

#pragma region Windows Form Designer generated code

    void InitializeComponent(void);
#pragma endregion

    System::Void clockButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void adminButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void LoginButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void drinkButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void addMenuItemButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void addDrinkButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void entreeButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void mainButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void dessertButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void addManagerButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void createnewadminButton_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void addWaiterButton_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void waiterCreateNewButton_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void clockinButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void timer1_Tick(System::Object ^ sender, System::EventArgs ^ e);

    System::Void addNewTableButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void createNewTableButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void tablesButton_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void addTables(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e);

    System::Void menuItem_Clicked(System::Object ^ sender, System::EventArgs ^ e);

    System::Void confirmOrderLayoutPanelTableLabel_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void eatinOrderLayoutPanelTableLabel_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void table_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void clockOutbutton_Click(System::Object ^ sender, System::EventArgs ^ e);

  private:
    System::Void tableOrderPayButton_Click(System::Object ^ sender, System::EventArgs ^ e);
};
} // namespace RMSPOS
