#include "charts.h"
#include "testing.h"


/*
* Write the necessary junk for the top of the chart
*/
static void writeTopBoilerPlateOfPieChart(std::ostream& out) {
    out << "<html>\n";
    out << "<head>\n";
    out << "<!--Load the AJAX API-->\n";
    out << "<script type=\"text/javascript\"";
    out << "src=\"https://www.google.com/jsapi\">";
    out << "</script>\n";
    out << "<script type=\"text/javascript\">\n";
    out << "google.load('visualization', '1.0',";
    out << " {'packages':['corechart']});\n";
    out << "google.setOnLoadCallback(drawChart);\n";
    out << "function drawChart() {\n";
    out << "var data=new google.visualization.DataTable();";
    out << "\n";
    out << "data.addColumn('string', 'Label');\n";
    out << "data.addColumn('number', 'Value');\n";
    out << "}\n";
    out << "</script>\n";
    out << "</head>\n";
}

/*
* Write the demo of the Pie Chart
*/
static void writeDataOfPieChart(std::ostream& out,
                                const std::vector<std::string>& labels,
                                const std::vector<double>& values) {
    out << "data.addRows([\n";
    int nLabels = labels.size();
    for (int i=0; i<nLabels; i++) {
        std::string label = labels[i];
        double value = values[i];
        out << "['" << label << "'," << value << "]";
        if (i!=nLabels-1) {
            out << ",";
        }
        out << "\n";
    }
    out << "]);\n";                                    
}

/*
 *  Write the boring bit at the bottom of a pie chart
 */
static void writeBottomBoilerPlateOfPieChart(std::ostream & out ) {
    out << "var options = {'title':'A Pie Chart',\n";
    out << "'width':400,\n";
    out << "'height':300\n";
    out << "};\n";
    out << "var chart = new google.visualization.PieChart(";
    out << "document.getElementById('chart_div'));\n";
    out << "chart.draw(data, options);\n";
    out << "}\n";
    out << "</script>\n";
    out << "</head>\n";
    out << "<body>\n";
    out << "<div id='chart_div'>\n";
    out << "</body>\n";
    out << "</html>";
}

/*
 *  Write the boring bit at the bottom of a pie chart
 */
void pieChart(const std::string& file,
              const std::vector<std::string>& labels,
              const std::vector<double>& values) {
    std::ofstream out;
    out.open(file.c_str());
    writeTopBoilerPlateOfPieChart(out);
    writeDataOfPieChart(out, labels, values);
    writeBottomBoilerPlateOfPieChart(out);
}

///////////////////////////////////////////
//
//   Tests for charts
//
///////////////////////////////////////////

static void testPieChart() {
    // checking manually by web browser
    std::vector<std::string> labels(10);
    std::vector<double> values(10);
    for (int i=0; i<10; i++) {
        std::stringstream ss;
        ss << "A Label " << i;
        labels[i] = ss.str();
        values[i] = (double)i;
    }
    pieChart("testPieChart.html", labels, values);
}

static void testPieChartData() {
    // automatically checking
    std::stringstream out;
    std::vector<std::string> labels(3);
    std::vector<double> values(3);
    for (int i=0; i<3; i++) {
        std::stringstream ss;
        ss << "A Label " << i;
        labels[i] = ss.str();
        INFO(labels[i])
        values[i] = (double)i;
    }
    writeDataOfPieChart(out, labels, values);
    std::string asString = out.str();
    std::stringstream expected;
    expected << "data.addRows([\n";
    expected << "['A Label 0',0],\n";
    expected << "['A Label 1',1],\n";
    expected << "['A Label 2',2],\n";
    std::string expectStr = expected.str();
    ASSERT(asString==expectStr);
}

void testCharts() {
    TEST(testPieChart);
    TEST(testPieChartData);
}