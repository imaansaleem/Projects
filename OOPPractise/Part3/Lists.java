public class Lists{
    private PhysicalClass[] PList;
    private int PSize;
    private WithLabs[] WList;
    private int WSize;
    private OnlineClass[] OList;
    private int OSize;

    public Lists() {
        PSize = 0;
        WSize = 0;
        OSize = 0;
        PList = new PhysicalClass[100];
        WList = new WithLabs[100];
        OList = new OnlineClass[100];
    }

    public PhysicalClass[] getPList() {
        return PList;
    }

    public OnlineClass[] getOList() {
        return OList;
    }

    public int getOSize() {
        return OSize;
    }

    void AddPlist(PhysicalClass p){
        PList[PSize] = p;
        PSize++;
    }

    void AddWList(WithLabs w){
        WList[WSize] = w;
        WSize++;
    }

    void AddOList(OnlineClass o){
        OList[OSize] = o;
        OSize++;
    }

    void DisplayCrns(String c){
        for(int i=0;i<PSize;i++){
            if(PList[i].getCode().equals(c))
                System.out.println(PList[i].getCRN());

            else if(WList[i].getCode().equals(c))
                System.out.println(WList[i].getCRN());

            else{
                String[] s = WList[i].getRoom();
                String[] v = WList[i].getLabNumber();
                for(int j=0;j<3;j++){
                    if(s[j].equals(c)) {
                        System.out.println(v[j]);
                    }
                }
            }
        }
    }

}
