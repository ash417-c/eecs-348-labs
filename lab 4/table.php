if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['num'])) {
        $num = intval($_POST['num']);
        echo "<h3>Multiplication Table (1 to $num)</h3>";
        echo "<table>";
        // Header row
        echo "<tr><th>x</th>";
        for ($col = 1; $col <= $num; $col++) {
            echo "<th>Col $col</th>";
        }
        echo "</tr>";
        // Table rows
        for ($row = 1; $row <= $num; $row++) {
            echo "<tr><th>Row $row</th>";
            for ($col = 1; $col <= $num; $col++) {
                echo "<td>" . ($row * $col) . "</td>";
            }
            echo "</tr>";
        }
        echo "</table>";
    }