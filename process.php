<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <!-- TODO: Update the author -->
        <meta name="author" content="Darby Lane">
        <title>Testing!</title>
        <!-- TODO: Update the description -->
        <meta name="description" content="Use this website to keep track of your yarn projects!">
        <link href="style.css" rel="stylesheet" type="text/css" media="screen" />
    </head>
    <body>
    	<header>
    		<h1>CS 2300</h1>
    		<h2>M3OEP</h2>
    		<!-- TODO: Change this h3 to your function name -->
    		<h3>Yarn Projects</h3>
    	</header>
        <?php
            // Create a folder for the user where the processing will take place. It will be named a random number (so that it's different for each submission).
                    $project_type = $_POST["project"];
                    $project_name = $_POST["name"];
                    $project_status = $_POST["status"];
                    $project_link = $_POST["link"];
                    $yarn_weight = $_POST["yarn_weight"];
                    $yarn_yards = $_POST["yarn_yards"];
                    $yarn_color = $_POST["yarn_color"];
                    $project_details = $_POST["details"];

                    //$rand_number = rand();
                    //while (file_exists($rand_number)) {
                      //  $rand_number = rand();
                    //}
                    //$command_mkdir = escapeshellcmd("mkdir " . $rand_number);
                    //$output_mkdir = shell_exec($command_mkdir);

                    // Copy the files into the folder.
                   // $files = ["Project.cpp", "Knitting_Project.cpp", "Crochet_Project.cpp", "Yarn.cpp", "yarn_projects.cpp", "Crochet_Project.h", "Yarn.h", "Knitting_Project.h", "Project.h"];
                   //             foreach ($files as $file) {
                   //                 shell_exec("cp " . escapeshellarg($file) . " " . escapeshellarg($rand_number));
                   //             }
                    $output = shell_exec("g++ -std=c++1y yarn_projects.cpp Project.cpp Knitting_Project.cpp Crochet_Project.cpp Yarn.cpp -o yarn_projects 2>&1;./yarn_projects " . escapeshellarg($project_type) . " " . escapeshellarg($project_name) . " " . escapeshellarg($project_status) . " " . escapeshellarg($project_link) . " " . escapeshellarg($yarn_weight) . " " . escapeshellarg($yarn_yards) . " " . escapeshellarg($yarn_color) . " " . escapeshellarg($project_details) . " 2>&1");

                    // Print the output from the C++ program to the webpage.
                    echo $output;

                    // Delete the folder
                    //array_map("unlink", glob($rand_number . "/*"));
                    //rmdir($rand_number);
        ?>
    </body>
</html>
