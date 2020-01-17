<h1 style="text-align: center;">Restaurant Management and Point of Sale System</h1>
<p style="text-align: center;"><strong>[Under Development]</strong></p>
<p>This is an implementation of a restaurant/bar management and Point of Sale system. The system provides tools to set and track menu items prices, order items and assign orders to tables, record staff check in and check out times, automatically or manually order supplies from distributors, monitor tables vaccancies, and staff availabilites.</p>
<p>The system provides a side panel to allow easy navigation through different sections. The side panel consists of explanatory images rather than texts to be easily understandable despite someone's language.</p>
<p align="center"><img src="https://github.com/oisy92/RMSPOS/blob/master/Images/Dashboard%20Explanation.jpg?raw=true" width="300" /></p>
<p style="text-align: left;" align="center">The system allows admins to customize tables positions so the table layout can accurately resemble the restaurant's actual layout, making it less confusing for waiters to identify tables. Furthermore, the system detects vacant and non vacant tables by coloring them green and red respectively. Hence, staff can quickly find tables for coming diners.&nbsp;</p>
<p align="center"><img src="https://github.com/oisy92/RMSPOS/blob/master/Images/Tables%20Layout.png?raw=true" width="900" /></p>
<p>The system includes a secured admins and super admins dashboards. Super Admins have the priviliges of:</p>
<ol>
<li>Add/Remove staff.</li>
<li>Add/Remove menu items.</li>
<li>Add/Remove tables.</li>
<li>Add/Remove admins.</li>
<li>View staff details</li>
</ol>
<p>admins have the priviliges of super admins, except adding/removing admins, and viewing staff details.</p>
<p align="center"><img src="https://raw.githubusercontent.com/oisy92/RMSPOS/master/Images/Admin%20Dashboard.png" width="900" /></p>
<p>The system records staff clock in and clock out times in an external database, allowing super admins to view the amount of hours worked, and expect pay. Furthermore, the system keeps count of on-shift staff by showing the number of clocked in staff at the footer.</p>
<p align="center"><img src="https://github.com/oisy92/RMSPOS/blob/master/Images/Staff%20Clock%20In%20Confirmation.png?raw=true" width="200" /></p>
<p style="text-align: left;" >The system includes 4 menu categories:</p>
<ol>
<li style="text-align: left;">Drinks</li>
<li style="text-align: left;">Entrees</li>
<li style="text-align: left;">Mains</li>
<li style="text-align: left;">Desserts</li>
</ol>
<p>Only admins and super admins have the <span id="osc_tag_system_11" class="osc_tag_system osc_error_green">privilege</span> of adding items to the categories, and only clocked in staff have the privilege of ordering menu items to tables.</p>
<p align="center"><img src="https://github.com/oisy92/RMSPOS/blob/master/Images/Drinks%20Menu.png?raw=true" width="900" /></p>
<p align="center"><img src="https://github.com/oisy92/RMSPOS/blob/master/Images/Entree%20Menu.png?raw=true" width="900" /></p>
<p align="center"><img src="https://github.com/oisy92/RMSPOS/blob/master/Images/Mains%20Menu.png?raw=true" width="900" /></p>
<p align="center"><img src="https://github.com/oisy92/RMSPOS/blob/master/Images/Desserts%20Menu.png?raw=true" width="900" /></p>
<h2>Features:</h2>
<ol>
<li>Table ordering: You can assign orders to tables from the software's simple user interface.</li>
<li>Tables customizing: You can customize the table layout in the software to accurately</li>
<li>resemble the actual layout of your restaurant, so it can be less confusing to your staff.</li>
<li>POS: You can use the software to process transactions.</li>
<li>Staff check in/check out: Your staff can securely log in and log out to record their check in and check out times. Allowing you to monitor their working times and breaks.</li>
<li>Order supplies: You can use the software to register suppliers and contact them through E-mail to order supplies.</li>
</ol>
<h2>Planned Development:</h2>
<p>This list will be <span id="osc_tag_system_13" class="osc_tag_system osc_error_green">continuously</span> edited to keep track of project progress.</p>
<ol>
<li>Develop Clock off implementation.</li>
<li>Develop supply ordering implemenetion.</li>
<li>Create email field for new staff and admins, and send their credentials to their emails.</li>
<li>Develop POS system.</li>
<li>Develop menu item price modification implementation.</li>
<li>Develop binding database to record data in case of software shutdown.</li>
<li>Develop Super Admin dashboard.</li>
</ol>
<p>The following items are not required, but would be great to have it included in the system:</p>
<ol>
<li>Staff shifts scheduling.</li>
<li>Connect system to Arduino board to simulate POS drawer opening/closing.</li>
</ol>
<h2>Prerequisites:</h2>
<ol>
<li>C++ environment (Preferably VS2019)</li>
<li>Common Language Support.</li>
</ol>
<h2>How To Build:</h2>
<ol>
<li>Open the project by clicking <code>RMSPOS.sln</code>.</li>
<li>Build the project.</li>
  <li>Navigate to <code>\x64\Debug</code> and run the exeutable <code>RMSPOS.exe</code>.</li>
</ol>
