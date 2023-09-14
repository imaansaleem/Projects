# CPU Scheduler Simulator 

This project involves the development of a program that operates with the following specifications:

## 1. Command Argument Options

The program should support command argument options for reading input data from a text file and specifying an output data file. The following command arguments must be used:
- `-f`: This option indicates the input file name.
- `-o`: This option indicates the output file name.

## 2. Input Data Format

This file should have three columns and unlimited rows. It must be text and
fields should delimit by “:” character. Below table represent structure of this
file

```
Burst Time:Arrival Time:Priority
10:0:0
5:0:0
```

Some data fields may not use at decision process so you can omits the values. But every process should have three of these values. At the Appendix section input.txt
file given as example. 

# Project Details

This project involves the development of a program for simulating CPU scheduling. The program should provide the following functionalities:

## 1. Command Argument Options

The program accepts the following command argument options:
- `-f`: Specifies the input file name.
- `-o`: Specifies the output file name.

Example usage:
```bash
python program.py -f input.txt -o output.txt
```

## 3. User Interaction

After first time executing simulator should ask for user to choose scheduling method. Menu should have at least four options. 

### CPU Scheduler Simulator
1) Scheduling Method (None)<br>
2) Preemptive Mode (Off)<br>
3) Show Result<br>
4) End Program<br>
Option ><br>

a) **Scheduling Method**: In this mode, the program obtains the scheduling method from the user. The available options are:
   - None: No scheduling method chosen
   - First Come, First Served Scheduling
   - Shortest-Job-First Scheduling
   - Priority Scheduling
   - Round-Robin Scheduling (The program should also obtain the time quantum value if this option is chosen)

b) **Preemptive Mode**: This mode can be clock-driven, where the clock is incremented each simulated second until all jobs have been serviced and left the system, or non-preemptive, where the dispatcher makes a decision after a process has terminated.

c) **Show Result**: If the user chooses this option, the program displays a report on the screen (as described in Step 4).

d) **End Program**: If the user chooses this option, the program displays all implemented scheduling results on the screen (as described in Step 4) and writes these results to the output file specified with the `-o` option. The simulator then terminates.

e) **Appendix Section**: This section should provide screen and file outputs identical to the ones described.

## 4. Gathering Statistics

Your program must gather statistics, compute, and report the following information:

a) The average waiting time that all jobs spend in the wait queue.

b) The waiting time that each job spends in the wait queue.

## 5. Additional Information

Keep in mind that some scheduling methods do not run in preemptive mode, so take care to implement them correctly.

## File input.txt sample content
5:0:3<br>
4:1:2<br>
3:1:1<br>
4:2:2<br>
3:3:1<br>

## output.txt/Screen output 
### Example 1
Scheduling Method: First Come First Served<br>
Process Waiting Times:<br>
P1: 0 ms<br>
P2: 4 ms<br>
P3: 8 ms<br>
P4: 10 ms<br>
P5: 13 ms<br>
Average Waiting Time: 7 ms<br>

### Example 2
Scheduling Method: Shortest Job First – Non-Preemptive<br>
Process Waiting Times:<br>
P1: 0 ms<br>
P2: 10 ms<br>
P3: 4 ms<br>
P4: 13 ms<br>
P5: 5 ms<br>
Average Waiting Time: 6.4 ms<br>

### Example 3
Scheduling Method: Shortest Job First –Preemptive<br>
Process Waiting Times:<br>
P1: 6 ms<br>
P2: 10 ms<br>
P3: 0 ms<br>
P4: 13 ms<br>
P5: 1 ms<br>
Average Waiting Time: 6 ms<br>

### Example 4
Scheduling Method: Priority Scheduling –Preemptive<br>
Process Waiting Times:<br>
P1: 14 ms<br>
P2: 6 ms<br>
P3: 0 ms<br>
P4: 9 ms<br>
P5: 1 ms<br>
Average Waiting Time: 6 ms<br>

### Example 6
Scheduling Method: Priority Scheduling – Non-Preemptive<br>
Process Waiting Times:<br>
P1: 0 ms<br>
P2: 10 ms<br>
P3: 4 ms<br>
P4: 13 ms<br>
P5: 5 ms<br>
Average Waiting Time: 6.4 ms<br>


### Example 7
Scheduling Method: Round Robin Scheduling – time_quantum=2<br>
Process Waiting Times:<br>
P1: 14 ms<br>
P2: 9 ms<br>
P3: 11 ms<br>
P4: 11 ms<br>
P5: 12 ms<br>
Average Waiting Time: 11.4 ms<br>

