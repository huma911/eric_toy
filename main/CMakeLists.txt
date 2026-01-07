set(INCLUDE_DIRS "." "ui/custom" "ui/generated" "ui/generated/guider_customer_fonts")
set(SOURCES "")
file(GLOB_RECURSE SOURCES ./*.c)

idf_component_register(
                        SRCS ${SOURCES}
                        INCLUDE_DIRS ${INCLUDE_DIRS}
                        )

spiffs_create_partition_image(storage ../spiffs FLASH_IN_PROJECT)