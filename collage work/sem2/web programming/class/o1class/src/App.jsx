import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  

  return (
    <>
      <div className='flex flex-wrap  gap-4 '>
        <div className='h-[100px] order-1 w-[200px] rounded-2xl shadow-2xl border-4
         hover:bg-slate-500 flex items-center justify-center bg-slate-400 '>1</div>
        <div className='h-[100px] order-3 w-[200px] rounded-2xl shadow-2xl border-4
         hover:bg-blue-500 flex items-center justify-center bg-blue-400 '>2</div>
        <div className='h-[100px] order-2 w-[200px] rounded-2xl shadow-2xl border-4
         hover:bg-red-500 flex items-center justify-center bg-red-400 '>3</div>
        <div className='h-[100px] order-5 w-[200px] rounded-2xl shadow-2xl border-4
         hover:bg-green-500 flex items-center justify-center bg-green-400 '>4</div>
        <div className='h-[100px] order-4 w-[200px] rounded-2xl shadow-2xl border-4
         hover:bg-yellow-500 flex items-center justify-center bg-yellow-400 '>5</div>
        <div className='h-[100px] order-6 w-[200px] rounded-2xl shadow-2xl border-4
         hover:bg-indigo-500 flex items-center justify-center bg-indigo-400 '>6</div>
    </div>
    </>
  ) 
}

export default App
