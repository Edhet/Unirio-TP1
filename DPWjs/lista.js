function fibonacci() {
    let x = 0, y = 1, z;
    for (i = 0; i < 20; i++) {
        console.log(x);
        z = x + y;
        x = y;
        y = z;
    }
}

function stringManipulation() {
    const string = `O Bacharelado em Sistemas de Informação da UNIRIO é um curso vespertino/noturno de graduação com duração prevista de 4 anos, com carga horária total de 3.240 horas-aula em regime de crédito semestral (Veja o Projeto Pedagógico do Curso). Atualmente o curso BSI-UNIRIO oferece 72 vagas anuais, com duas entradas semestrais de 36 alunos através do Sistema de Seleção Unificado (SiSU), que é o processo seletivo baseado no resultado do Exame Nacional do Ensino Médio (ENEM).`;

    console.log(string.length);
    console.log(string.toUpperCase());
    console.log(string.substring(20, 50));
    console.log(string.replace("Sistemas", "S."));

    let reverseString = "";
    for (i = string.length - 1; i >= 0; i--)
        reverseString += string[i];
    console.log(reverseString);

    console.log(string.substring(0, string.length / 3));
    console.log(string.substring(string.length / 3, string.length / 3 * 2));
    console.log(string.substring(string.length / 3 * 2, string.length - 1));

}

function calcDates() {
    const datum = new Date();
    console.log(datum.getHours() + datum.getDate());
    console.log(datum.getMinutes() + datum.getMonth());
    console.log(datum.getSeconds() + datum.getFullYear());
}

function date() {
    const datum = new Date();
    console.log(`${datum.getHours()}:${datum.getMinutes()}:${datum.getSeconds()} ${datum.getDate()}/${datum.getMonth() + 1}/${datum.getFullYear()}`);
}

function calcNumbs() {
    for (i = 1; i <= 100; i += 3) {
        if (i <= 100)
            console.log(`sqrt of ${i} is ${Math.sqrt(i)}`);
    }
}

function vectorManipulation() {
    let colores = ["c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9", "c10", "c11", "c12"];
    const datum = new Date();
    hours = (datum.getHours() > 12) ? datum.getHours() - 12 : datum.getHours();
    console.log(hours);

    switch (hours) {
        case 0:
            console.log(colores[0]);
            break;
        case 1:
            console.log(colores[1]);
            break;
        case 2:
            console.log(colores[2]);
            break;
        case 3:
            console.log(colores[3]);
            break;
        case 4:
            console.log(colores[4]);
            break;
        case 5:
            console.log(colores[5]);
            break;
        case 6:
            console.log(colores[6]);
            break;
        case 7:
            console.log(colores[7]);
            break;
        case 8:
            console.log(colores[8]);
            break;
        case 9:
            console.log(colores[9]);
            break;
        case 10:
            console.log(colores[10]);
            break;
        case 11:
            console.log(colores[11]);
            break;
        case 12:
            console.log(colores[12]);
            break;
    }

    colores.splice(1, 1);
    colores.push("c13");
    console.log(colores.toString());
}

function objectManipulation() {
    let aluno = {
        PrimeiroNome: "Maria Flor",
        UltimoNome: "Silva",
        Matricula: 20221210090,
        Curso: "BSI"
    };

    aluno.Idade = 18;

    console.log(aluno);

    console.log(returnName(aluno));
}

function returnName(obj) {
    return `${obj.PrimeiroNome} ${obj.UltimoNome}`
}