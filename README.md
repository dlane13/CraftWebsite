# CraftWebsite
This is a website to help me keep track of my yarn projects!

Darby Lane

Summary of my program:
This program uses a website and file to keep track of yarn projects that the user enters, as well as details about these projects including the name of the project, the type of yarn project (knit or crochet), the status of the project (not started, in progress, or complete), a link to the pattern for the project, info about the yarn for the project, and optional further detail about the project.
Each entry by the user is stored in a Project object, which holds all of the information about the project, and the fields of these objects are added to a file of html code which is then returned at the end of the program.
The user can go back to the home page of the website and add another project, and the file is updated to store that project and then prints all of its projects once the form is submitted.

HOW TO RUN THIS PROGRAM (i think) (only for UVM Students): Using FileZilla, get into your personal website (netid.w3.uvm.edu) and after cloning the repo onto local computer, copy it into the www-root folder of the website.
Now go to netid.w3.uvm.edu/M3OEP-dlane2/projects.html, and it should work! I don't think any other software is required.

The program starts in HTML, prompting the user for information about their project. Once every section is filled out, the user hits submit, which then passes the user input to a PHP script. This script passes commands to the command line which compile the C++ file (yarn_projects.cpp) and link it to the class files it uses. The user input is passed as arguments to the executable, and the output of the C++ file, which is HTML code, is then returned to the HTMl file which originally called the PHP file. The website then prints all of the projects which have been entered by the user in the lifetime of the file that they are written to, and the user can go back to the original page to enter more projects.

HTML is very good for the visual components of the website, such as headers, text boxes, dropdown menus, etc. It uses CSS for the color, font, centering, etc. CSS is only meant for this, so it's very useful. PHP is good for handling the dynamic aspect of the website, like user input. If there was no interaction with the website, HTML would be great alone, but due to the input component, PHP is needed to handle this and pass it along to my C++ program. Finally, C++ is good for creating my Project objects and doing more of the general-purpose programming. It is good for writing out to the file, as well as performing actions with the user input.

I am not aware of any bugs at this time.

Future work I would like to put into this program would be enabling the user to delete entries, or change fields of previous entries, i.e. updating the status of a proejct if they've finished it.

Credit: Professor Lisa Dion, provided starter code 
