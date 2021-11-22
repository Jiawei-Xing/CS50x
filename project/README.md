# Bacterial Taxonomy Search tool
#### Video Demo: https://youtu.be/eNxMn7slmwI
#### Description
Bacterial taxonomy is important for microbiologists and evolutionary biologists. There are some levels of bacterial classification: phylum, class, order, family, genus, and species. Genome taxonomy database is a great resource for bacterial taxonomy information. To get taxonomy information for multiple bacterial genomes at the same time, here I build Bacterial Taxonomy Search tool (BTS). This tool searches for bacterial taxonomy information from Genome Taxonomy Database using genome assembly numbers. It can also summarize the result at different taxonomy levels.

#### Components
static/styles.css: CSS file, including header, body, text area, buttons, tables, footer, and thematic breaks.
templates/layout.html: general HTML template for each webpage, including the header and the footer.
templates/home.html: HTML file for the home page, including a text area and a button.
templates/taxonomy.html: HTML file for the taxonomy page, including a table.
templates/summary.html: HTML file for the summary page, including seven tables separated by lines.
application.py: main python script using SQL and flask, including three functions (home, taxonomy, and summary).
create_db.py: Python script for creating the bacteria table inside the gtdb database. The CSV file was downloaded from GTDB. Each line, representing a bacterial genome, is inserted into the bacteria table inside the gtdb SQL database.
gtdb.db: SQL database containing the bacteria table, including eight columns: genomes, phylum, class, order1 (to disambiguate with the ORDER clause in SQL), family, genus, and species.
requirements.txt: required modules in python, including flask and cs50 (for SQL).
README.md: description, components, instructions, and common questions.

#### Instructions
##### Homepage (input)
Copy and paste bacterial genome assembly numbers into the query text area. Genomes should be separated by spaces, tabs, or newlines. Click the search button to get bacterial taxonomy.
##### Taxonomy (output)
Taxonomy information of each genome is obtained from GTDB. Information includes domain, phylum, class, order, family, genus, and species. Click the summary button to summarize at different taxonomy levels.
##### Summary
Group and count numbers of different types at different taxonomy levels.

#### Common questions
##### How to get genome accession numbers?
Genome accession numbers can be obtained from NCBI database. You can use tools such as Esearch for multiple queries.
##### How to download the taxonomy information?
You can select and copy directly on the webpage. Or right click, select view page source, and copy the data from the html file.
##### How to analyze the result?
The summary page shows components of the input data at different taxonomy levels. General questions could be: do they have a wide or narrow distribution? Are they present in novel or ancient bacteria groups? Are they Gram positive or negative bacteria? ...
