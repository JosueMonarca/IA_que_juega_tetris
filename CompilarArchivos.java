import java.io.IOException;

final String ROOT = System.getProperty("user.dir");
final String EXECUTABLE_NAME = "tetris.exe";

void main(String[] args) {
    String os = System.getProperty("os.name").startsWith("Windows") ? "cmd.exe" : "bash";
    String FLAG = os.equals("cmd.exe") ? "/c" : "-c";
    final String CONTROLLER_PATH = ROOT + (os.equals("cmd.exe") ? "\\src\\controller" : "/src/controller");
    final String VIEW_PATH = ROOT + (os.equals("cmd.exe") ? "\\src\\view" : "/src/view");
    final String EVERY_FILES_C = os.equals("cmd.exe") ? "\\*.c " : "/*.c";

    if (args.length == 0) {
        IO.println("Por favor, proporciona un comando: CC, CV o CA");
        return;
    }

    int result = switch (args[0]) {
        case "CC" -> {
            IO.println("Compilando archivos del controlador...");
            String comando = "gcc " + CONTROLLER_PATH + EVERY_FILES_C + " -o " + EXECUTABLE_NAME;
            yield mediatorCommand(comando, os, ROOT, FLAG);
        }
        case "CV" -> {
            IO.println("Compilando archivos de la vista...");
            String comando = "gcc " + VIEW_PATH + EVERY_FILES_C + " -o " + EXECUTABLE_NAME;
            yield  mediatorCommand(comando, os, ROOT, FLAG);
        }
        case "CA" -> {
            IO.println("Compilando todos los archivos...");
            String comando = os.equals("cmd.exe")
                ? "gcc " + CONTROLLER_PATH + EVERY_FILES_C + VIEW_PATH + EVERY_FILES_C + " -o " + EXECUTABLE_NAME
                : "gcc $(find src -name \"*.c\") -o " + EXECUTABLE_NAME;
            yield  mediatorCommand(comando, os, ROOT, FLAG);
        }
        default  -> {
            IO.println("Comando no reconocido: " + args[0]);
            yield -1;
        }
    };

    if (result == 0) IO.println("Compilación exitosa.");
    else {IO.println("Error durante la compilación."); return;}

    IO.println("Ejecutando archivo");
    String comando = os.equals("cmd.exe") ? "tetris.exe" : "./tetris.exe";
    result = mediatorCommand(comando, os, ROOT, FLAG);
    if (result == -1){IO.print("Error al ejecutar archivo"); return;}
    else IO.println("Archivo ejecutado con exito...");
    
    IO.println("Limpiando archivos compilados...");
    comando = os.equals("cmd.exe") ? "del tetris.exe" : "rm tetris.exe";
    result = mediatorCommand(comando, os, ROOT, FLAG);
    if(result == -1) IO.println("Error al limpiar archivos compilados"); 
    else IO.println("Archivos compilados limpiados con exito...");
    
}

int runCommand(String command, String os, String directory,String flag) throws IOException, InterruptedException {
    ProcessBuilder builder = new ProcessBuilder(os,flag,command);
    builder.redirectErrorStream(true);
    builder.directory(new java.io.File(directory));
    builder.inheritIO();
    Process proceso = builder.start();
    return proceso.waitFor();
}

int mediatorCommand (String command, String os, String directory,String flag){
    try {
        return runCommand(command, os, directory, flag);
    } catch ( IOException | InterruptedException _) {
        return -1;
    }
}