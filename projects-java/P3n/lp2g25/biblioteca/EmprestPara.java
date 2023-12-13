package lp2g25.biblioteca;
import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

public class EmprestPara implements Serializable  {
    private  GregorianCalendar dataEmprestimo;
    private GregorianCalendar dataDevolucaoPrevista;
    private int codigoUsuario;

    public EmprestPara(GregorianCalendar dataDevolucaoPrevista, int codigoUsuario) {
        this.dataEmprestimo = new GregorianCalendar();
        this.dataDevolucaoPrevista = dataDevolucaoPrevista;
        this.codigoUsuario = codigoUsuario;
    }

    @Override
    public String toString() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        String dataEmprestimoStr = sdf.format(dataEmprestimo.getTime());
        String dataDevolucaoPrevistaStr = sdf.format(dataDevolucaoPrevista.getTime());

        return "{" +
                "dataEmprestimo=" + dataEmprestimoStr +
                ", dataDevolucaoPrevista=" + dataDevolucaoPrevistaStr +
                ", codigoUsuario=" + codigoUsuario +
                '}';
    }

    public GregorianCalendar getDataEmprestimo() {
        return dataEmprestimo;
    }

    public void setDataEmprestimo(GregorianCalendar dataEmprestimo) {
        this.dataEmprestimo = dataEmprestimo;
    }

    public GregorianCalendar getDataDevolucaoPrevista() {
        return dataDevolucaoPrevista;
    }

    public void setDataDevolucaoPrevista(GregorianCalendar dataDevolucaoPrevista) {
        this.dataDevolucaoPrevista = dataDevolucaoPrevista;

    }
    
    public int getcodigoUsuario() {
        return codigoUsuario;
    }
    
    public void setcodigoUsuario(int codigoUsuario) {
        this.codigoUsuario = codigoUsuario;
    }


 
}

