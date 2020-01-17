<h1 style="text-align: center;">Restaurant Management and Point of Sale System</h1>
<p style="text-align: center;"><strong>[Under Development]</strong></p>
<p>This is an implementation of a restaurant/bar management and Point of Sale system. The system provides tools to set and track menu items prices, order items and assign orders to tables, record staff check in and check out times, automatically or manually order supplies from distributors, monitor tables vaccancies, and staff availabilites.</p>
<p align="center">
  <img width="900" src="https://github.com/oisy92/RMSPOS/blob/master/Images/Tables%20Layout.png?raw=true">
</p>
<p>The system provides easy to use dashboard, it relies mostly on descriptory images rather than texts. Hence, it can be used internationally.&nbsp;</p>
<p align="center">
  <img width="900" src="https://raw.githubusercontent.com/oisy92/RMSPOS/master/Images/Admin%20Dashboard.png">
</p>
<p>The system includes a secured admins and super admins dashboards. Super Admins have the priviliges of:</p>
<ol>
<li>Add/Remove staff.</li>
<li>Add/Remove menu items.</li>
<li>Add/Remove tables.</li>
<li>Add/Remove admins.</li>
<li>View staff details</li>
</ol>
<p>admins have the priviliges of super admins, except point 4 and 5.</p>


<p align="center">
  <img width="900" src="https://github.com/oisy92/RMSPOS/blob/master/Images/Create%20New%20Staff.png?raw=true">
</p>

<p align="center">
  <img width="250" src="https://github.com/oisy92/RMSPOS/blob/master/Images/Staff%20Add%20Confirmation.png">
</p>

<p align="center">
  <img width="900" src="https://github.com/oisy92/RMSPOS/blob/master/Images/Staff%20Clock%20In.png">
</p>
<p align="center">
  <img width="250" src="https://github.com/oisy92/RMSPOS/blob/master/Images/Staff%20Clock%20In%20Confirmation.png">
</p>

<p>The system records staff clock in times and saves it to a database. The database can be viewed by super admins only.</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<h2>Features:</h2>
<ol>
<li>Table ordering: You can assign orders to tables from the software's simple user interface.</li>
<li>Tables customizing: You can customize the tables layout in the software to accurately</li>
<li>resemble the actual layout of your restaurant, so it can be less confusing to your staff.</li>
<li>POS: You can use the software to process transactions.</li>
<li>Staff check in/check out: Your staff can securely log in and log out to record their check in and check out times. Allowing you to monitor their working times and breaks.</li>
<li>Order supplies: You can use the software to register suppliers and contact them through E-mail to order supplies.</li>
</ol>
<h2>Planned Development:</h2>
<p>This list will be continously edited to keep track of project progress.</p>
<ol>
<li>Develop Clock off implementation.</li>
<li>Develop supply ordering implemenetion.</li>
<li>Create email field for new staff and admins, and send their credentials to their emails.</li>
<li>Develop POS system.</li>
<li>Develop menu item price modification implementation.</li>
<li>Develop binding database to record data in case of software shutdown.</li>
<li>Develop Super Admin dashboard.</li>
</ol>
<p>The following items are not required, but would be great to have it included in the system</p>
<ol>
<li>Staff shifts scheduling.</li>
<li>Connect system to Arduino board to simulate POS drawer opening/closing.</li>
</ol>
<h2>Prequisites:</h2>
<ol>
<li>Visual Studio&nbsp;2019.</li>
<li>Common Language Support.</li>
</ol>
<h2>How To Build:</h2>
<ol>
<li>Open the project by clicking `RMSPOS.sln`.</li>
<li>Build the project.</li>
<li>Navigate to `\x64\Debug` and run the exeutable `RMSPOS.exe`.</li>
</ol>
