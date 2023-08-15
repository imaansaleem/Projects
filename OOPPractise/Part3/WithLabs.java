public class WithLabs extends Class{

    private String code;
    private String labs;
    private String[] labNumber;
    private String[] room;

    public WithLabs(String CRN, String prefix, String lectureTitle, String graduate, String modality, String code, String labs, String[] labN, String[] rooms) {
        super(CRN, prefix,lectureTitle,graduate,modality);
        this.code = code;
        this.labs = labs;
        labNumber = labN;
        room = rooms;
    }

    public String getCode() {
        return code;
    }

    public String[] getRoom() {
        return room;
    }

    public String[] getLabNumber() {
        return labNumber;
    }

    public String toString(){
        return getCRN() + ',' + getPrefix() + ',' + getLectureTitle() + ',' + getGraduate() + ',' + getModality() + ',' + code+ ',' + labs + '\n'+ labNumber[0] + ',' + room[0] + '\n'+ labNumber[1] + ',' + room[1] + '\n'+ labNumber[2] + ',' + room[2];
    }
}
