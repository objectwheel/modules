### Copy qmldir file and then generate plugins.qmltypes file

FILES_TO_COPY = $$_PRO_FILE_PWD_/qmldir
DESTINATION_DIR = $$shell_quote($$shell_path($$OUT_PWD/$$DESTDIR))

for (FILE, FILES_TO_COPY) {
    FILE_PATH = $$shell_quote($$shell_path($$FILE))
    QMAKE_POST_LINK += $$QMAKE_COPY $$FILE_PATH $$DESTINATION_DIR $$escape_expand(\n\t)
}

# qmltypes files are only needed by the intellisense of Objectwheel
!android:!ios {
    QMLDUMPER_PATH = $$absolute_path("qmlplugindump", $$dirname(QMAKE_QMAKE))
    MODULE_NAME = Objectwheel
    !equals(TARGET, "objectwheelmodule"):MODULE_NAME = Objectwheel.$$basename(DESTDIR)
    QMAKE_POST_LINK += cd $$shell_quote($$shell_path($$clean_path($$OUT_PWD/../Modules))) && \
    $$QMLDUMPER_PATH -nonrelocatable $$MODULE_NAME $$VERSION \
    $$shell_quote($$shell_path(.)) > \
    $$shell_quote($$shell_path($$relative_path($$clean_path($$OUT_PWD/$$DESTDIR/plugins.qmltypes), \
                                               $$clean_path($$OUT_PWD/../Modules)))) \
    $$escape_expand(\n\t)
}
