import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Lists l = new Lists();
        readFromFile(l);
        System.out.println("There are " + l.getOSize() + " lectures offered");
        System.out.print("Enter the classroom: ");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.print("The crns held in " + input + " are: ");
        l.DisplayCrns(input);
        writeToFile(l);
        System.out.println("lecturesOnly.txt is created\n");
        System.out.println("Goodbye !");
    }

    public static void readFromFile(Lists l) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("lec.txt"));
        String line;

        String CRN, prefix, lectureTitle,graduate,modality, code,labs;

        while ((line = reader.readLine()) != null) {
            String[] values = line.split(",");

            String[] labNumber = new String[3];
            String[] room = new String[3];

            if(values.length == 5){ // in case of online
                CRN = values[0];
                prefix = values[1];
                lectureTitle = values[2];
                graduate = values[3];
                modality = values[4];
                OnlineClass o = new OnlineClass(CRN, prefix,lectureTitle,graduate,modality);
                l.AddOList(o);
            }

            else if (values.length == 7) { //in case of mixed
                CRN = values[0];
                prefix = values[1];
                lectureTitle = values[2];
                graduate = values[3];
                modality = values[4];
                code = values[5];
                labs = values[6];

                if(labs.equalsIgnoreCase("yes")){
                    for(int i=0;i<3;i++){ //read the next 3 lines
                        line = reader.readLine();
                        String[] val = line.split(",");
                        labNumber[i] = val[0];
                        room[i] = val[1];
                    }
                    WithLabs w = new WithLabs(CRN, prefix,lectureTitle,graduate,modality,code,labs,labNumber,room);
                    l.AddWList(w);
                }

                else{
                    PhysicalClass p = new PhysicalClass(CRN, prefix,lectureTitle,graduate,modality,code,labs);
                    l.AddPlist(p);
                }
            }
        }

        reader.close();
    }

    public static void writeToFile(Lists l) {
        PhysicalClass[] PList = l.getPList();
        OnlineClass[] OList = l.getOList();

        try {
            FileWriter writer = new FileWriter("lecturesOnly.txt");
            writer.write("Online Lectures\n");
            for (OnlineClass o : OList) {
                if(o!=null)
                    writer.write(o.toString() + "\n");
            }

            writer.write("\nLectures with No Lab\n");
            for (PhysicalClass p : PList) {
                if(p!=null)
                    writer.write(p.toString() + "\n");
            }

            writer.close();
        } catch (IOException e) {
            System.out.println("An error occurred while writing to file.");
            e.printStackTrace();
        }

    }
}
