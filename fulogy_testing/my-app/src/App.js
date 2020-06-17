import React from 'react';
import './App.css';
import MainPage from "./Main";
import Header from "./Header";
import Footer from "./Footer";
import Info from "./Info";

function App() {
    return (
        <div className="App">
            <Header/>
            <MainPage/>
            <Footer/>
            <Info/>
        </div>
    );
}

export default App;
