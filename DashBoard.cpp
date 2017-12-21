/*
 * The MIT License
 *
 * Copyright 2017 Schuemi.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


/* 
 * File:   DashBoard.cpp
 * Author: Schuemi
 * 
 * Created on 12. Dezember 2017, 11:28
 */

#include "DashBoard.h"
#include "StarField.h"
#include "math.h"
#include <avr/pgmspace.h>
#include <Arduboy2Audio.h>





const uint8_t PROGMEM DashBoard::title[] = {
0x00,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf0,0xc0,0x00,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0x80,0x00,0x00,0x00,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0x80,0x00,0x00,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0x80,0x00,0x00,0x80,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf0,0x00,0x00,0xc0,0xc0,0xc0,0x00,0x00,0x00,0xc0,0xc0,0xc0,0x00,0x00,0x80,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0x80,0x00,0xc0,0xc0,0xc0,0x80,0xc0,0xc0,0xc0,0x00,0x00,0xc0,0xff,0xfc,0xf8,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xc0,0xc0,0xc0,0xc0,0xc0,0x00,0x00,0x02,0x0e,0x3e,0xfe,0xfc,0xf0,0xc0,0x80,0x00,0x00,0xf7,0xf7,0xf7,0x07,0x07,0x07,0xff,0xff,0xff,0x00,0xc0,0xe7,0xf7,0xe7,0x87,0x07,0xe7,0xf7,0xf7,0x00,0xe7,0xf7,0xf7,0x07,0x07,0x07,0x07,0x07,0x06,0x00,0xff,0xff,0xff,0x07,0x77,0xf7,0xf7,0xf7,0xe7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0xfe,0xfe,0x00,0x00,0x00,0x00,0xfe,0xfe,0xfe,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0xe4,0xf7,0xf7,0xe7,0x07,0x07,0xf7,0xf7,0xe7,0x00,0xff,0xff,0xff,0x07,0x07,0x07,0x07,0x07,0x04,0x07,0xff,0xff,0xff,0x00,0x07,0x04,0x00,0xf7,0xf7,0xe7,0x07,0x07,0x0f,0xff,0xff,0xff,0x08,0x78,0xf8,0xf8,0xf8,0xfb,0xff,0xff,0xff,0xfe,0x00,0xff,0xff,0xff,0xf8,0xf8,0xf8,0xff,0xff,0xff,0x00,0x7f,0xff,0xff,0xfb,0xfb,0xf8,0xff,0xff,0xff,0x00,0x7f,0xff,0xff,0xf8,0xf8,0xf8,0xf8,0xf8,0x18,0x00,0xff,0xff,0xff,0xf8,0xf8,0xfb,0xfb,0xfb,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xff,0xff,0xf8,0xf8,0xf8,0xf8,0xff,0xff,0xff,0x00,0x00,0xff,0xff,0xff,0xf8,0xf8,0xf8,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0xfb,0xfb,0xf8,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x7f,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x07,0x07,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};






DashBoard::DashBoard() {
   m_starField = new StarField(0, 0, 128, 64, 4);
   g_arduboy = (Arduboy2*)getInstance();
   m_startLevel = 1;
   reset();
}

void DashBoard::reset() {
    g_arduboy->setRGBled(0,0,0);
    m_fontPosition = 128;
    m_bounce = 1;
    m_startGame = false;
    m_startHighScore = false;
    m_currSelected = 0;
    m_itemsCount = 2;
    if (EEPROM.read(EEPROM_GAME_CLEARED_BYTE + EEPROM_STORAGE_SPACE_START) == 0x32) m_itemsCount = 3;
    
}

DashBoard::~DashBoard() {
}


void DashBoard::draw() {
    uint8_t itemsy = 38;
    uint8_t isSave;
    g_arduboy->pollButtons();
    
    g_arduboy->clear();
    
    if (m_fontPosition > 35) 
        m_fontPosition-= 4;
    else if (m_bounce > -0.7) {
        m_bounce-= 0.03;
        m_fontPosition-= sin(m_bounce)*4;
    } 
    
    g_arduboy->drawBitmap(m_fontPosition, 5, title, 120, 31);
    
    
    
    
    g_arduboy->drawPixel(34, itemsy + 3 + (m_currSelected * 8));
    g_arduboy->drawPixel(33, itemsy + 2 + (m_currSelected * 8));
    g_arduboy->drawPixel(33, itemsy + 3 + (m_currSelected * 8));
    g_arduboy->drawPixel(33, itemsy + 4 + (m_currSelected * 8));
    g_arduboy->setCursor(38, itemsy);
    if (g_arduboy->audio.enabled())
        g_arduboy->print(F("SOUND: ON"));
    else
        g_arduboy->print(F("SOUND: OFF"));
    
    itemsy += 8;g_arduboy->setCursor(38, itemsy);
    isSave = EEPROM.read(EEPROM_AUTOSAVE_BYTE + EEPROM_STORAGE_SPACE_START);
    if (isSave) 
       g_arduboy->print(F("SAVE : ON"));
    else
       g_arduboy->print(F("SAVE : OFF"));
    

    if (m_itemsCount == 3) {
        itemsy += 8;g_arduboy->setCursor(38, itemsy);
        g_arduboy->print(F("LEVEL: ")); g_arduboy->print(m_startLevel);
    }
    

    
    m_starField->move();
    m_starField->draw(false);
        
    if (g_arduboy->justPressed(A_BUTTON)){
       m_startHighScore = true;
    }
    if (g_arduboy->justPressed(B_BUTTON)){
       m_startGame = true;
       g_arduboy->initRandomSeed();
    }
    if (g_arduboy->justPressed(DOWN_BUTTON)){
        m_currSelected++;
        if (m_currSelected == m_itemsCount) m_currSelected = 0;
    }
    
    
    
    if (g_arduboy->justPressed(UP_BUTTON)){
        if (m_currSelected == 0) m_currSelected = m_itemsCount - 1; else m_currSelected--;

    }
    if (g_arduboy->justPressed(LEFT_BUTTON) || g_arduboy->justPressed(RIGHT_BUTTON)){
        if (m_currSelected == 0){
            g_arduboy->audio.toggle();
            g_arduboy->audio.saveOnOff();
        }
        if (m_currSelected == 1){
           if (isSave) EEPROM.write(EEPROM_AUTOSAVE_BYTE + EEPROM_STORAGE_SPACE_START, 0); else  EEPROM.write(EEPROM_AUTOSAVE_BYTE + EEPROM_STORAGE_SPACE_START, 1);
        }
    }
    if (g_arduboy->justPressed(LEFT_BUTTON)){
        
        if (m_currSelected == 2){
            m_startLevel--;
            if (m_startLevel == 0) m_startLevel = 8;

        }
    }
    if (g_arduboy->justPressed(RIGHT_BUTTON)){
       
        if (m_currSelected == 2){
            m_startLevel++;
            if (m_startLevel == 9) m_startLevel = 1;
        }
    }
    g_arduboy->display();
    
}