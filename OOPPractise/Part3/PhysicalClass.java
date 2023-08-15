import java.security.SecureRandom;

public class PhysicalClass extends Class {
    private String code;
    private String labs;

    public PhysicalClass(String CRN, String prefix, String lectureTitle, String graduate, String modality, String code, String labs) {
        super(CRN, prefix,lectureTitle,graduate,modality);
        this.code = code;
        this.labs = labs;
    }

    public String getCode() {
        return code;
    }

    public String toString(){
        return getCRN() + ',' + getPrefix() + ',' + getLectureTitle() + ',' + getGraduate() + ',' + getModality() + ',' + code+ ',' + labs;
    }
}

