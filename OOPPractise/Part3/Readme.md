## UCF Computer Science Department Class Analysis

At the UCF Computer Science Department (CSD), classes are categorized as either lectures (LEC) or labs (LAB). Each class, whether it's a lecture or lab, is associated with the following attributes: 

- CRN (Course Number, a unique five-digit identifier)
- Prefix (e.g., COP3330)
- Title (e.g., Introduction to Object Oriented Programming)
- Location (e.g., CB 2-201)
- Modality (Online, Face-to-Face, or Mixed Mode)
- Graduate or Undergraduate status

Lecture and lab information is provided in a text file named lec.txt. Each line in lec.txt follows this format:<br>

CRN,PREFIX,LECTURE TITLE,GRADUTE/UNDERGRADUTE/MODALITY,BUILDING CODE-ROOM NUMBER,LAB(YES/NO) <br>

## Examples:
89745,COT6578,Advanced Computer theory,Graduate,F2F,PSY-108,No<br>
32658,COT6578,Advanced Computer theory,Graduate,Mixed,LPS-35,No<br>
That means that the CSD offers two sections of COT6578, one is F2F and the other is online. Both of those sections 
don’t have labs.<br>
When a lecture has a lab, the labs’ information is provided right after the lecture 
information<br>

## Examples:
69745,COP5698, Programming Languages,Graduate,F2F,CB2-122,YES<br>
19745,MSB-123<br>
36598,PSY-100 <br>
20315,HSA1-116<br>

That means the COP5698 with crn 69745 has three labs. 19745, 36598 and 20315 are the crns of the labs.<br>
MSB-123, PSY-100 and HSA1-116 are the building-room numbers where those labs are scheduled to take place.<br>

Note that if the Modality is Online, then the line of the lec.txt has the form:<br>
CRN,PREFIX,LECTURE TITLE,GRADUTE/UNDERGRADUTE/ONLINE<br> 
## Example:
89745,COP4578,Software Engineering,Undergraduate,Online<br>

## Your Java program should:

1. Count the number of online classes offered by the CSD.
2. Display the CRNs of lectures and labs being held in a user-specified classroom.
3. Create a text file (lecturesOnly.txt) listing online and no-lab lectures.

## Sample Run:
- There are 4 online lectures offered.
- Enter the classroom: MSB-123
The CRNs held in MSB-123 are: 19745
- lecturesOnly.txt is created.
Goodbye!

Given the content of lec.txt, lecturesOnly.txt should contain:
## Online Lectures
66636,DIG2158,Introduction to Digital Systems,Undergraduate,Online
36636,SOF2058,Introduction to Software,Undergraduate,Online
51180,CDL2587,Introduction to Computers,Undergraduate,online
36637,SOF2058,Introduction to Software,Undergraduate,Online

## Lectures with No Lab
89745,COT6578,Advanced Computer Theory,Graduate,F2F,PSY-108,No
32658,COT6578,Advanced Computer Theory,Graduate,Mixed,LPS-35,No
