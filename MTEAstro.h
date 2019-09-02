

#ifndef MTEASTRO_H
#define MTEASTRO_H

#include <wchar.h>


#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
#    define MTE_DECL_EXPORT __declspec(dllexport)
#elif defined(__linux__) || defined(__linux)
#    define MTE_DECL_EXPORT __attribute__((visibility("default")))
#endif




/** @file MTEAstro.h
 * @brief MTEAstro.h
 * @n Заголовочный файл, описывающий интерфейсы C,
 * необходимые для работы с библиотекой
*/

extern "C" {

/**
 * @brief                   Загрузить эфемериды звезд из файла
 * @param[in] path          полный или относительный путь к файлу эфемерид
 * @return                  количество звезд в эфемеридах (0 если эфемериды не были загружены)
 */
MTE_DECL_EXPORT
unsigned int loadEphemerides(const wchar_t * path);

/**
 * @brief   Получить количество загруженных звезд
 * @param[out]   total количество звезд каталога HIPARCOS
 * @param[out]   navigational количество навигационных звезд МАЕ
 */
MTE_DECL_EXPORT
void getStarsCount(unsigned int * total,
                   unsigned int * navigational);

/**
 * @brief Указать параметры наблюдателя
 * @param[in] timeUTC всемирное время в формате time_t
 * @param[in] latitude широта места наблюдателя в градусах
 * @param[in] longitude долгота места наблюдателя в градусах
 * @param[in] elevation  возвышение места наблюдателя над уровнем моря в метрах
 * @return false в случае ошибки
 */
MTE_DECL_EXPORT
bool setObserver(long long timeUTC,
                 double latitude,
                 double longitude,
                 double elevation);


/**
 * @brief Получить информацию о звезде каталога HIPARCOS по ее номеру в каталоге [hipparcos_id]
 * @param[in] hipparcos_id номер звезды в каталоге HIPARCOS
 * @param[out] navigational_id соответствующий номер звезды в каталоге навигационных звезд МАЕ
 * (0 если нет соответствия)
 * @param[out] name Наименование звезды (EN)
 * @param[out] name_ru Наименование звезды (RU)
 * @param[out] constellation Наименование созвездия (EN)
 * @param[out] constellation_ru Наименование созвездия (RU)
 * @param[out] alphabet Символ звезды в зозвездии
 * @param[out] right_ascension Прямое восхождение (градусы)
 * @param[out] declination Склонение (градусы)
 * @param[out] azimuth Азимут (градусы)
 * @param[out] elevation Возвышение над уровнем моря (градусы)
 * @param[out] magnitude Звездная величина
 * @param[out] red Составляющая красного в показателе цвета
 * @param[out] green Составляющая зеленого в показателе цвета
 * @param[out] blue Составляющая синего в показателе цвета
 * @return Номер звезды в каталоге HIPARCOS (0 в случае ошибки)
 */
MTE_DECL_EXPORT
unsigned int getHipparcosStar(unsigned int hipparcos_id,
                              unsigned int * navigational_id,
                              char * name,
                              char * name_ru,
                              char * constellation,
                              char * constellation_ru,
                              char * alphabet,
                              double * right_ascension,
                              double * declination,
                              double * azimuth,
                              double * elevation,
                              double * magnitude,
                              double * red,
                              double * green,
                              double * blue );
/**
 * @brief Получить информацию о звезде каталога МАЕ по ее номеру в каталоге [navigational_id]
 * @param navigational_id номер звезды в каталоге МАЕ
 * @param hipparcos_id соответствующий номер звезды в каталоге HIPARCOS
 * (0 если нет соответствия)
 * @param name Наименование звезды (EN)
 * @param name_ru Наименование звезды (RU)
 * @param constellation Наименование созвездия (EN)
 * @param constellation_ru Наименование созвездия (RU)
 * @param alphabet Символ звезды в зозвездии
 * @param[out] right_ascension Прямое восхождение (градусы)
 * @param[out] declination Склонение (градусы)
 * @param[out] azimuth Азимут (градусы)
 * @param[out] elevation Возвышение над уровнем моря (градусы)
 * @param[out] magnitude Звездная величина
 * @param[out] red Составляющая красного в показателе цвета
 * @param[out] green Составляющая зеленого в показателе цвета
 * @param[out] blue Составляющая синего в показателе цвета
 * @return Номер звезды в каталоге МАЕ (0 в случае ошибки)
 */
MTE_DECL_EXPORT
unsigned int getNavigationalStar(unsigned int navigational_id,
                              unsigned int * hipparcos_id,
                              char * name,
                              char * name_ru,
                              char * constellation,
                              char * constellation_ru, char * alphabet,
                              double * right_ascension,
                              double * declination,
                              double * azimuth,
                              double * elevation,
                              double * magnitude,
                              double * red,
                              double * green,
                              double * blue );
/**
 * @brief getSun Получить информацию о Солнце
 * @param[out] right_ascension Прямое восхождение (градусы)
 * @param[out] declination Склонение (градусы)
 * @param[out] azimuth Азимут (градусы)
 * @param[out] elevation Возвышение над уровнем моря (градусы)
 * @param apparent_diametr Видимый диаметр (градусы)
 * @return false в случае ошибки
 */
MTE_DECL_EXPORT
bool getSun(double * right_ascension,
            double * declination,
            double * azimuth,
            double * elevation,
            double * apparent_diametr);

/**
 * @brief Получить информацию о Луне
 * @param[out] right_ascension Прямое восхождение (градусы)
 * @param[out] declination Склонение (градусы)
 * @param[out] azimuth Азимут (градусы)
 * @param[out] elevation Возвышение над уровнем моря (градусы)
 * @param age Возраст в сутках
 * @param orientation Ориентация в градусах по часовой стрелке
 * @param month Подолжительность лунного месяца в сутках
 * @param apparent_diametr Видимый диаметр (градусы)
 * @return false в случае ошибки
 */
MTE_DECL_EXPORT
bool getMoon(double * right_ascension,
             double * declination,
             double * azimuth,
             double * elevation,
             double * age,
             double * orientation, double * month,
             double * apparent_diametr);

/**
 * @brief Получить информацию об объекте солнечной системы
 * @param[in] индекс объекта, соответствующий описанию перечеслимого типа Planet
 * @param[out] right_ascension Прямое восхождение (градусы)
 * @param[out] declination Склонение (градусы)
 * @param[out] azimuth Азимут (градусы)
 * @param[out] elevation Возвышение над уровнем моря (градусы)
 * @param[out] magnitude Звездная величина
 * @param[out] apparent_diametr Видимый диаметр (градусы)
 * @return false в случае ошибки
 */
MTE_DECL_EXPORT
bool getPlanet(unsigned int planet,
               double * right_ascension,
               double * declination,
               double * azimuth,
               double * elevation,
               double * magnitude,
               double * apparent_diametr);

/**
 * @brief Перечислимый тип, описывающий индексы объектов солнечной системы,
 * передаваемые в качестве аргумента функции getPlanet
 */
enum Planet
{
    Mercury = 0,    ///< Меркурий
    Venus   = 1,    ///< Венера
    Mars    = 2,    ///< Марс
    Jupiter = 3,    ///< Юпитер
    Saturn  = 4,    ///< Сатурн
    Uranus  = 5,    ///< Уран
    Neptune = 6,    ///< Нептун
    Pluto   = 7,    ///< Плутон
    Sun     = 8,    ///< Солнце
    Moon    = 9,    ///< Луна
};


}

#endif // MTEASTRO_H
