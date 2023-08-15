public class OnlineClass extends Class{
    public OnlineClass(String CRN, String prefix, String lectureTitle, String graduate, String modality) {
        super(CRN, prefix,lectureTitle,graduate,modality);
    }

    public String toString(){
        return getCRN() + ',' + getPrefix() + ',' + getLectureTitle() + ',' + getGraduate() + ',' + getModality();
    }
}
