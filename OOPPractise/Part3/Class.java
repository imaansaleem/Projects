abstract class Class {
    private String CRN;
    private String prefix;
    private String lectureTitle;
    private String Graduate;
    private String Modality;

    public Class(String CRN, String prefix, String lectureTitle, String graduate, String modality) {
        this.CRN = CRN;
        this.prefix = prefix;
        this.lectureTitle = lectureTitle;
        Graduate = graduate;
        Modality = modality;
    }

    public String getCRN() {
        return CRN;
    }

    public String getPrefix() {
        return prefix;
    }

    public String getLectureTitle() {
        return lectureTitle;
    }

    public String getGraduate() {
        return Graduate;
    }

    public String getModality() {
        return Modality;
    }

}
